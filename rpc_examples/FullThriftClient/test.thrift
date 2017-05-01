struct message {
  1: i32 uid,
  2: string line,
}

exception InvalidValueException {
  1: i32 error_code,
  2: string error_msg
}

service MessageManager {
  void ping(),
  i32 add_message(1:message m) throws (1: InvalidValueException e),
  message get_message(1:i32 uid) throws (1: InvalidValueException e),
  oneway void clear_list()
}
