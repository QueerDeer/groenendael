#!/usr/bin/env python

import sys
import time

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

#  result = dict()
  t = 0.0
  linestring = open(sys.argv[2], 'r').read()
  message = dict()
  message['line'] = linestring
  del linestring

  try:
    num_messages = int(sys.argv[1])
  except:
    num_messages = 1

  params = {}
  params['message'] = message
   
  for msg_count in range(num_messages):
    requestor = make_requestor(SERVER_HOST, SERVER_PORT, MAIL_PROTOCOL)
    t1 = int(round(time.time()))
    result = requestor.request('send', params)
    t2 = int(round(time.time()))
    t += (t2 - t1)
    print(sys.getsizeof(result['line']))

print(t)
my_file = open("T_CALLBACK_AVRO_test.txt", "a")
my_file.write("for" + sys.argv[2] + " file and avro-rpc_binary: " + str(t/100) + " ms\n")
my_file.close()


