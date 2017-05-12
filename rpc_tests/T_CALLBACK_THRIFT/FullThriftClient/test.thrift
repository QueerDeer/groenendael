struct message {
  1: binary line,
}

exception InvalidValueException {
  1: i32 error_code,
  2: string error_msg
}

service MessageManager {
  message add_message(1:message m) throws (1: InvalidValueException e),
}
