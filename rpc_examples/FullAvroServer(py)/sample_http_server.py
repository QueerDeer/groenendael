#!/usr/bin/env python

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
from avro import ipc
from avro import protocol

MAIL_PROTOCOL = protocol.parse(open("test.json", "rb").read())
SERVER_ADDRESS = ('localhost', 9090)

class MailResponder(ipc.Responder):
  def __init__(self):
    ipc.Responder.__init__(self, MAIL_PROTOCOL)

  def invoke(self, message, request):
      request_content = request['message']
      response = "Sent message with uid %(uid)s and line %(line)s" % \
                 request_content
      return response

class MailHandler(BaseHTTPRequestHandler):
  def do_POST(self):
    self.responder = MailResponder()
    call_request_reader = ipc.FramedReader(self.rfile)
    call_request = call_request_reader.read_framed_message()
    resp_body = self.responder.respond(call_request)
    self.send_response(200)
    self.send_header('Content-Type', 'avro/binary')
    self.end_headers()
    resp_writer = ipc.FramedWriter(self.wfile)
    resp_writer.write_framed_message(resp_body)

if __name__ == '__main__':
  mail_server = HTTPServer(SERVER_ADDRESS, MailHandler)
  mail_server.allow_reuse_address = True
  mail_server.serve_forever()
