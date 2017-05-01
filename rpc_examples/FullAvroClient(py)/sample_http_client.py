#!/usr/bin/env python

import sys

from avro import ipc
from avro import protocol

MAIL_PROTOCOL = protocol.parse(open("test.json", "rb").read())
SERVER_HOST = 'localhost'
SERVER_PORT = 9090

class UsageError(Exception):
  def __init__(self, value):
    self.value = value
  def __str__(self):
    return repr(self.value)

def make_requestor(server_host, server_port, protocol):
  client = ipc.HTTPTransceiver(SERVER_HOST, SERVER_PORT)
  return ipc.Requestor(protocol, client)

if __name__ == '__main__':
  if len(sys.argv) not in [2, 3]:
    raise UsageError("Usage: <line> [<count>]")

  message = dict()
  message['uid'] = 42
  message['line'] = sys.argv[1]

  try:
    num_messages = int(sys.argv[2])
  except:
    num_messages = 1

  params = {}
  params['message'] = message
   
  for msg_count in range(num_messages):
    requestor = make_requestor(SERVER_HOST, SERVER_PORT, MAIL_PROTOCOL)
    result = requestor.request('send', params)
    print("Result: " + result)

