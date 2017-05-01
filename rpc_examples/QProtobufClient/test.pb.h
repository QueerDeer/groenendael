// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#ifndef PROTOBUF_test_2eproto__INCLUDED
#define PROTOBUF_test_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000002 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace test {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_test_2eproto();
void protobuf_AssignDesc_test_2eproto();
void protobuf_ShutdownFile_test_2eproto();

class test_line;

// ===================================================================

class test_line : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:test.test_line) */ {
 public:
  test_line();
  virtual ~test_line();

  test_line(const test_line& from);

  inline test_line& operator=(const test_line& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const test_line& default_instance();

  void Swap(test_line* other);

  // implements Message ----------------------------------------------

  inline test_line* New() const { return New(NULL); }

  test_line* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const test_line& from);
  void MergeFrom(const test_line& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(test_line* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 uid = 1;
  void clear_uid();
  static const int kUidFieldNumber = 1;
  ::google::protobuf::int32 uid() const;
  void set_uid(::google::protobuf::int32 value);

  // optional string line = 2;
  void clear_line();
  static const int kLineFieldNumber = 2;
  const ::std::string& line() const;
  void set_line(const ::std::string& value);
  void set_line(const char* value);
  void set_line(const char* value, size_t size);
  ::std::string* mutable_line();
  ::std::string* release_line();
  void set_allocated_line(::std::string* line);

  // @@protoc_insertion_point(class_scope:test.test_line)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr line_;
  ::google::protobuf::int32 uid_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_test_2eproto();
  friend void protobuf_AssignDesc_test_2eproto();
  friend void protobuf_ShutdownFile_test_2eproto();

  void InitAsDefaultInstance();
  static test_line* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// test_line

// optional int32 uid = 1;
inline void test_line::clear_uid() {
  uid_ = 0;
}
inline ::google::protobuf::int32 test_line::uid() const {
  // @@protoc_insertion_point(field_get:test.test_line.uid)
  return uid_;
}
inline void test_line::set_uid(::google::protobuf::int32 value) {
  
  uid_ = value;
  // @@protoc_insertion_point(field_set:test.test_line.uid)
}

// optional string line = 2;
inline void test_line::clear_line() {
  line_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& test_line::line() const {
  // @@protoc_insertion_point(field_get:test.test_line.line)
  return line_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void test_line::set_line(const ::std::string& value) {
  
  line_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:test.test_line.line)
}
inline void test_line::set_line(const char* value) {
  
  line_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:test.test_line.line)
}
inline void test_line::set_line(const char* value, size_t size) {
  
  line_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:test.test_line.line)
}
inline ::std::string* test_line::mutable_line() {
  
  // @@protoc_insertion_point(field_mutable:test.test_line.line)
  return line_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* test_line::release_line() {
  // @@protoc_insertion_point(field_release:test.test_line.line)
  
  return line_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void test_line::set_allocated_line(::std::string* line) {
  if (line != NULL) {
    
  } else {
    
  }
  line_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), line);
  // @@protoc_insertion_point(field_set_allocated:test.test_line.line)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace test

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_test_2eproto__INCLUDED
