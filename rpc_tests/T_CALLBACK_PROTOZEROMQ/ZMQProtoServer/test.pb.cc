// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "test.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace test {

namespace {

const ::google::protobuf::Descriptor* file_content_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  file_content_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_test_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_test_2eproto() {
  protobuf_AddDesc_test_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "test.proto");
  GOOGLE_CHECK(file != NULL);
  file_content_descriptor_ = file->message_type(0);
  static const int file_content_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(file_content, line_),
  };
  file_content_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      file_content_descriptor_,
      file_content::default_instance_,
      file_content_offsets_,
      -1,
      -1,
      -1,
      sizeof(file_content),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(file_content, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(file_content, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_test_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      file_content_descriptor_, &file_content::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_test_2eproto() {
  delete file_content::default_instance_;
  delete file_content_reflection_;
}

void protobuf_AddDesc_test_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_test_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\ntest.proto\022\004test\"\034\n\014file_content\022\014\n\004li"
    "ne\030\002 \001(\014b\006proto3", 56);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "test.proto", &protobuf_RegisterTypes);
  file_content::default_instance_ = new file_content();
  file_content::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_test_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_test_2eproto {
  StaticDescriptorInitializer_test_2eproto() {
    protobuf_AddDesc_test_2eproto();
  }
} static_descriptor_initializer_test_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int file_content::kLineFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

file_content::file_content()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:test.file_content)
}

void file_content::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

file_content::file_content(const file_content& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:test.file_content)
}

void file_content::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  line_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

file_content::~file_content() {
  // @@protoc_insertion_point(destructor:test.file_content)
  SharedDtor();
}

void file_content::SharedDtor() {
  line_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
  }
}

void file_content::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* file_content::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return file_content_descriptor_;
}

const file_content& file_content::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_test_2eproto();
  return *default_instance_;
}

file_content* file_content::default_instance_ = NULL;

file_content* file_content::New(::google::protobuf::Arena* arena) const {
  file_content* n = new file_content;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void file_content::Clear() {
// @@protoc_insertion_point(message_clear_start:test.file_content)
  line_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

bool file_content::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:test.file_content)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bytes line = 2;
      case 2: {
        if (tag == 18) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadBytes(
                input, this->mutable_line()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:test.file_content)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:test.file_content)
  return false;
#undef DO_
}

void file_content::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:test.file_content)
  // optional bytes line = 2;
  if (this->line().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBytesMaybeAliased(
      2, this->line(), output);
  }

  // @@protoc_insertion_point(serialize_end:test.file_content)
}

::google::protobuf::uint8* file_content::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:test.file_content)
  // optional bytes line = 2;
  if (this->line().size() > 0) {
    target =
      ::google::protobuf::internal::WireFormatLite::WriteBytesToArray(
        2, this->line(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:test.file_content)
  return target;
}

int file_content::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:test.file_content)
  int total_size = 0;

  // optional bytes line = 2;
  if (this->line().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::BytesSize(
        this->line());
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void file_content::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:test.file_content)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const file_content* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const file_content>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:test.file_content)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:test.file_content)
    MergeFrom(*source);
  }
}

void file_content::MergeFrom(const file_content& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:test.file_content)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.line().size() > 0) {

    line_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.line_);
  }
}

void file_content::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:test.file_content)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void file_content::CopyFrom(const file_content& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:test.file_content)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool file_content::IsInitialized() const {

  return true;
}

void file_content::Swap(file_content* other) {
  if (other == this) return;
  InternalSwap(other);
}
void file_content::InternalSwap(file_content* other) {
  line_.Swap(&other->line_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata file_content::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = file_content_descriptor_;
  metadata.reflection = file_content_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// file_content

// optional bytes line = 2;
void file_content::clear_line() {
  line_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& file_content::line() const {
  // @@protoc_insertion_point(field_get:test.file_content.line)
  return line_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void file_content::set_line(const ::std::string& value) {
  
  line_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:test.file_content.line)
}
 void file_content::set_line(const char* value) {
  
  line_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:test.file_content.line)
}
 void file_content::set_line(const void* value, size_t size) {
  
  line_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:test.file_content.line)
}
 ::std::string* file_content::mutable_line() {
  
  // @@protoc_insertion_point(field_mutable:test.file_content.line)
  return line_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* file_content::release_line() {
  // @@protoc_insertion_point(field_release:test.file_content.line)
  
  return line_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void file_content::set_allocated_line(::std::string* line) {
  if (line != NULL) {
    
  } else {
    
  }
  line_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), line);
  // @@protoc_insertion_point(field_set_allocated:test.file_content.line)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace test

// @@protoc_insertion_point(global_scope)
