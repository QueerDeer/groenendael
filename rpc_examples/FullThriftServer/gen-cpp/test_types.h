/**
 * Autogenerated by Thrift Compiler (0.10.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef test_TYPES_H
#define test_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/cxxfunctional.h>




class message;

class InvalidValueException;

typedef struct _message__isset {
  _message__isset() : uid(false), line(false) {}
  bool uid :1;
  bool line :1;
} _message__isset;

class message : public virtual ::apache::thrift::TBase {
 public:

  message(const message&);
  message& operator=(const message&);
  message() : uid(0), line() {
  }

  virtual ~message() throw();
  int32_t uid;
  std::string line;

  _message__isset __isset;

  void __set_uid(const int32_t val);

  void __set_line(const std::string& val);

  bool operator == (const message & rhs) const
  {
    if (!(uid == rhs.uid))
      return false;
    if (!(line == rhs.line))
      return false;
    return true;
  }
  bool operator != (const message &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const message & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(message &a, message &b);

inline std::ostream& operator<<(std::ostream& out, const message& obj)
{
  obj.printTo(out);
  return out;
}

typedef struct _InvalidValueException__isset {
  _InvalidValueException__isset() : error_code(false), error_msg(false) {}
  bool error_code :1;
  bool error_msg :1;
} _InvalidValueException__isset;

class InvalidValueException : public ::apache::thrift::TException {
 public:

  InvalidValueException(const InvalidValueException&);
  InvalidValueException& operator=(const InvalidValueException&);
  InvalidValueException() : error_code(0), error_msg() {
  }

  virtual ~InvalidValueException() throw();
  int32_t error_code;
  std::string error_msg;

  _InvalidValueException__isset __isset;

  void __set_error_code(const int32_t val);

  void __set_error_msg(const std::string& val);

  bool operator == (const InvalidValueException & rhs) const
  {
    if (!(error_code == rhs.error_code))
      return false;
    if (!(error_msg == rhs.error_msg))
      return false;
    return true;
  }
  bool operator != (const InvalidValueException &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const InvalidValueException & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
  mutable std::string thriftTExceptionMessageHolder_;
  const char* what() const throw();
};

void swap(InvalidValueException &a, InvalidValueException &b);

inline std::ostream& operator<<(std::ostream& out, const InvalidValueException& obj)
{
  obj.printTo(out);
  return out;
}



#endif
