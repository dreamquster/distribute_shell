// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Security.proto

#ifndef PROTOBUF_Security_2eproto__INCLUDED
#define PROTOBUF_Security_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace hadoop {
namespace common {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_Security_2eproto();
void protobuf_AssignDesc_Security_2eproto();
void protobuf_ShutdownFile_Security_2eproto();

class TokenProto;
class GetDelegationTokenRequestProto;
class GetDelegationTokenResponseProto;
class RenewDelegationTokenRequestProto;
class RenewDelegationTokenResponseProto;
class CancelDelegationTokenRequestProto;
class CancelDelegationTokenResponseProto;

// ===================================================================

class TokenProto : public ::google::protobuf::Message {
 public:
  TokenProto();
  virtual ~TokenProto();

  TokenProto(const TokenProto& from);

  inline TokenProto& operator=(const TokenProto& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TokenProto& default_instance();

  void Swap(TokenProto* other);

  // implements Message ----------------------------------------------

  TokenProto* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TokenProto& from);
  void MergeFrom(const TokenProto& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required bytes identifier = 1;
  inline bool has_identifier() const;
  inline void clear_identifier();
  static const int kIdentifierFieldNumber = 1;
  inline const ::std::string& identifier() const;
  inline void set_identifier(const ::std::string& value);
  inline void set_identifier(const char* value);
  inline void set_identifier(const void* value, size_t size);
  inline ::std::string* mutable_identifier();
  inline ::std::string* release_identifier();
  inline void set_allocated_identifier(::std::string* identifier);

  // required bytes password = 2;
  inline bool has_password() const;
  inline void clear_password();
  static const int kPasswordFieldNumber = 2;
  inline const ::std::string& password() const;
  inline void set_password(const ::std::string& value);
  inline void set_password(const char* value);
  inline void set_password(const void* value, size_t size);
  inline ::std::string* mutable_password();
  inline ::std::string* release_password();
  inline void set_allocated_password(::std::string* password);

  // required string kind = 3;
  inline bool has_kind() const;
  inline void clear_kind();
  static const int kKindFieldNumber = 3;
  inline const ::std::string& kind() const;
  inline void set_kind(const ::std::string& value);
  inline void set_kind(const char* value);
  inline void set_kind(const char* value, size_t size);
  inline ::std::string* mutable_kind();
  inline ::std::string* release_kind();
  inline void set_allocated_kind(::std::string* kind);

  // required string service = 4;
  inline bool has_service() const;
  inline void clear_service();
  static const int kServiceFieldNumber = 4;
  inline const ::std::string& service() const;
  inline void set_service(const ::std::string& value);
  inline void set_service(const char* value);
  inline void set_service(const char* value, size_t size);
  inline ::std::string* mutable_service();
  inline ::std::string* release_service();
  inline void set_allocated_service(::std::string* service);

  // @@protoc_insertion_point(class_scope:hadoop.common.TokenProto)
 private:
  inline void set_has_identifier();
  inline void clear_has_identifier();
  inline void set_has_password();
  inline void clear_has_password();
  inline void set_has_kind();
  inline void clear_has_kind();
  inline void set_has_service();
  inline void clear_has_service();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* identifier_;
  ::std::string* password_;
  ::std::string* kind_;
  ::std::string* service_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_Security_2eproto();
  friend void protobuf_AssignDesc_Security_2eproto();
  friend void protobuf_ShutdownFile_Security_2eproto();

  void InitAsDefaultInstance();
  static TokenProto* default_instance_;
};
// -------------------------------------------------------------------

class GetDelegationTokenRequestProto : public ::google::protobuf::Message {
 public:
  GetDelegationTokenRequestProto();
  virtual ~GetDelegationTokenRequestProto();

  GetDelegationTokenRequestProto(const GetDelegationTokenRequestProto& from);

  inline GetDelegationTokenRequestProto& operator=(const GetDelegationTokenRequestProto& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetDelegationTokenRequestProto& default_instance();

  void Swap(GetDelegationTokenRequestProto* other);

  // implements Message ----------------------------------------------

  GetDelegationTokenRequestProto* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetDelegationTokenRequestProto& from);
  void MergeFrom(const GetDelegationTokenRequestProto& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required string renewer = 1;
  inline bool has_renewer() const;
  inline void clear_renewer();
  static const int kRenewerFieldNumber = 1;
  inline const ::std::string& renewer() const;
  inline void set_renewer(const ::std::string& value);
  inline void set_renewer(const char* value);
  inline void set_renewer(const char* value, size_t size);
  inline ::std::string* mutable_renewer();
  inline ::std::string* release_renewer();
  inline void set_allocated_renewer(::std::string* renewer);

  // @@protoc_insertion_point(class_scope:hadoop.common.GetDelegationTokenRequestProto)
 private:
  inline void set_has_renewer();
  inline void clear_has_renewer();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::std::string* renewer_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_Security_2eproto();
  friend void protobuf_AssignDesc_Security_2eproto();
  friend void protobuf_ShutdownFile_Security_2eproto();

  void InitAsDefaultInstance();
  static GetDelegationTokenRequestProto* default_instance_;
};
// -------------------------------------------------------------------

class GetDelegationTokenResponseProto : public ::google::protobuf::Message {
 public:
  GetDelegationTokenResponseProto();
  virtual ~GetDelegationTokenResponseProto();

  GetDelegationTokenResponseProto(const GetDelegationTokenResponseProto& from);

  inline GetDelegationTokenResponseProto& operator=(const GetDelegationTokenResponseProto& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GetDelegationTokenResponseProto& default_instance();

  void Swap(GetDelegationTokenResponseProto* other);

  // implements Message ----------------------------------------------

  GetDelegationTokenResponseProto* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GetDelegationTokenResponseProto& from);
  void MergeFrom(const GetDelegationTokenResponseProto& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .hadoop.common.TokenProto token = 1;
  inline bool has_token() const;
  inline void clear_token();
  static const int kTokenFieldNumber = 1;
  inline const ::hadoop::common::TokenProto& token() const;
  inline ::hadoop::common::TokenProto* mutable_token();
  inline ::hadoop::common::TokenProto* release_token();
  inline void set_allocated_token(::hadoop::common::TokenProto* token);

  // @@protoc_insertion_point(class_scope:hadoop.common.GetDelegationTokenResponseProto)
 private:
  inline void set_has_token();
  inline void clear_has_token();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::hadoop::common::TokenProto* token_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_Security_2eproto();
  friend void protobuf_AssignDesc_Security_2eproto();
  friend void protobuf_ShutdownFile_Security_2eproto();

  void InitAsDefaultInstance();
  static GetDelegationTokenResponseProto* default_instance_;
};
// -------------------------------------------------------------------

class RenewDelegationTokenRequestProto : public ::google::protobuf::Message {
 public:
  RenewDelegationTokenRequestProto();
  virtual ~RenewDelegationTokenRequestProto();

  RenewDelegationTokenRequestProto(const RenewDelegationTokenRequestProto& from);

  inline RenewDelegationTokenRequestProto& operator=(const RenewDelegationTokenRequestProto& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RenewDelegationTokenRequestProto& default_instance();

  void Swap(RenewDelegationTokenRequestProto* other);

  // implements Message ----------------------------------------------

  RenewDelegationTokenRequestProto* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RenewDelegationTokenRequestProto& from);
  void MergeFrom(const RenewDelegationTokenRequestProto& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .hadoop.common.TokenProto token = 1;
  inline bool has_token() const;
  inline void clear_token();
  static const int kTokenFieldNumber = 1;
  inline const ::hadoop::common::TokenProto& token() const;
  inline ::hadoop::common::TokenProto* mutable_token();
  inline ::hadoop::common::TokenProto* release_token();
  inline void set_allocated_token(::hadoop::common::TokenProto* token);

  // @@protoc_insertion_point(class_scope:hadoop.common.RenewDelegationTokenRequestProto)
 private:
  inline void set_has_token();
  inline void clear_has_token();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::hadoop::common::TokenProto* token_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_Security_2eproto();
  friend void protobuf_AssignDesc_Security_2eproto();
  friend void protobuf_ShutdownFile_Security_2eproto();

  void InitAsDefaultInstance();
  static RenewDelegationTokenRequestProto* default_instance_;
};
// -------------------------------------------------------------------

class RenewDelegationTokenResponseProto : public ::google::protobuf::Message {
 public:
  RenewDelegationTokenResponseProto();
  virtual ~RenewDelegationTokenResponseProto();

  RenewDelegationTokenResponseProto(const RenewDelegationTokenResponseProto& from);

  inline RenewDelegationTokenResponseProto& operator=(const RenewDelegationTokenResponseProto& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RenewDelegationTokenResponseProto& default_instance();

  void Swap(RenewDelegationTokenResponseProto* other);

  // implements Message ----------------------------------------------

  RenewDelegationTokenResponseProto* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RenewDelegationTokenResponseProto& from);
  void MergeFrom(const RenewDelegationTokenResponseProto& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required uint64 newExpiryTime = 1;
  inline bool has_newexpirytime() const;
  inline void clear_newexpirytime();
  static const int kNewExpiryTimeFieldNumber = 1;
  inline ::google::protobuf::uint64 newexpirytime() const;
  inline void set_newexpirytime(::google::protobuf::uint64 value);

  // @@protoc_insertion_point(class_scope:hadoop.common.RenewDelegationTokenResponseProto)
 private:
  inline void set_has_newexpirytime();
  inline void clear_has_newexpirytime();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint64 newexpirytime_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_Security_2eproto();
  friend void protobuf_AssignDesc_Security_2eproto();
  friend void protobuf_ShutdownFile_Security_2eproto();

  void InitAsDefaultInstance();
  static RenewDelegationTokenResponseProto* default_instance_;
};
// -------------------------------------------------------------------

class CancelDelegationTokenRequestProto : public ::google::protobuf::Message {
 public:
  CancelDelegationTokenRequestProto();
  virtual ~CancelDelegationTokenRequestProto();

  CancelDelegationTokenRequestProto(const CancelDelegationTokenRequestProto& from);

  inline CancelDelegationTokenRequestProto& operator=(const CancelDelegationTokenRequestProto& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CancelDelegationTokenRequestProto& default_instance();

  void Swap(CancelDelegationTokenRequestProto* other);

  // implements Message ----------------------------------------------

  CancelDelegationTokenRequestProto* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CancelDelegationTokenRequestProto& from);
  void MergeFrom(const CancelDelegationTokenRequestProto& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // required .hadoop.common.TokenProto token = 1;
  inline bool has_token() const;
  inline void clear_token();
  static const int kTokenFieldNumber = 1;
  inline const ::hadoop::common::TokenProto& token() const;
  inline ::hadoop::common::TokenProto* mutable_token();
  inline ::hadoop::common::TokenProto* release_token();
  inline void set_allocated_token(::hadoop::common::TokenProto* token);

  // @@protoc_insertion_point(class_scope:hadoop.common.CancelDelegationTokenRequestProto)
 private:
  inline void set_has_token();
  inline void clear_has_token();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::hadoop::common::TokenProto* token_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_Security_2eproto();
  friend void protobuf_AssignDesc_Security_2eproto();
  friend void protobuf_ShutdownFile_Security_2eproto();

  void InitAsDefaultInstance();
  static CancelDelegationTokenRequestProto* default_instance_;
};
// -------------------------------------------------------------------

class CancelDelegationTokenResponseProto : public ::google::protobuf::Message {
 public:
  CancelDelegationTokenResponseProto();
  virtual ~CancelDelegationTokenResponseProto();

  CancelDelegationTokenResponseProto(const CancelDelegationTokenResponseProto& from);

  inline CancelDelegationTokenResponseProto& operator=(const CancelDelegationTokenResponseProto& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const CancelDelegationTokenResponseProto& default_instance();

  void Swap(CancelDelegationTokenResponseProto* other);

  // implements Message ----------------------------------------------

  CancelDelegationTokenResponseProto* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CancelDelegationTokenResponseProto& from);
  void MergeFrom(const CancelDelegationTokenResponseProto& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:hadoop.common.CancelDelegationTokenResponseProto)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;


  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[1];

  friend void  protobuf_AddDesc_Security_2eproto();
  friend void protobuf_AssignDesc_Security_2eproto();
  friend void protobuf_ShutdownFile_Security_2eproto();

  void InitAsDefaultInstance();
  static CancelDelegationTokenResponseProto* default_instance_;
};
// ===================================================================


// ===================================================================

// TokenProto

// required bytes identifier = 1;
inline bool TokenProto::has_identifier() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TokenProto::set_has_identifier() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TokenProto::clear_has_identifier() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TokenProto::clear_identifier() {
  if (identifier_ != &::google::protobuf::internal::kEmptyString) {
    identifier_->clear();
  }
  clear_has_identifier();
}
inline const ::std::string& TokenProto::identifier() const {
  return *identifier_;
}
inline void TokenProto::set_identifier(const ::std::string& value) {
  set_has_identifier();
  if (identifier_ == &::google::protobuf::internal::kEmptyString) {
    identifier_ = new ::std::string;
  }
  identifier_->assign(value);
}
inline void TokenProto::set_identifier(const char* value) {
  set_has_identifier();
  if (identifier_ == &::google::protobuf::internal::kEmptyString) {
    identifier_ = new ::std::string;
  }
  identifier_->assign(value);
}
inline void TokenProto::set_identifier(const void* value, size_t size) {
  set_has_identifier();
  if (identifier_ == &::google::protobuf::internal::kEmptyString) {
    identifier_ = new ::std::string;
  }
  identifier_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TokenProto::mutable_identifier() {
  set_has_identifier();
  if (identifier_ == &::google::protobuf::internal::kEmptyString) {
    identifier_ = new ::std::string;
  }
  return identifier_;
}
inline ::std::string* TokenProto::release_identifier() {
  clear_has_identifier();
  if (identifier_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = identifier_;
    identifier_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void TokenProto::set_allocated_identifier(::std::string* identifier) {
  if (identifier_ != &::google::protobuf::internal::kEmptyString) {
    delete identifier_;
  }
  if (identifier) {
    set_has_identifier();
    identifier_ = identifier;
  } else {
    clear_has_identifier();
    identifier_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required bytes password = 2;
inline bool TokenProto::has_password() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void TokenProto::set_has_password() {
  _has_bits_[0] |= 0x00000002u;
}
inline void TokenProto::clear_has_password() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void TokenProto::clear_password() {
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    password_->clear();
  }
  clear_has_password();
}
inline const ::std::string& TokenProto::password() const {
  return *password_;
}
inline void TokenProto::set_password(const ::std::string& value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(value);
}
inline void TokenProto::set_password(const char* value) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(value);
}
inline void TokenProto::set_password(const void* value, size_t size) {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  password_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TokenProto::mutable_password() {
  set_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    password_ = new ::std::string;
  }
  return password_;
}
inline ::std::string* TokenProto::release_password() {
  clear_has_password();
  if (password_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = password_;
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void TokenProto::set_allocated_password(::std::string* password) {
  if (password_ != &::google::protobuf::internal::kEmptyString) {
    delete password_;
  }
  if (password) {
    set_has_password();
    password_ = password;
  } else {
    clear_has_password();
    password_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string kind = 3;
inline bool TokenProto::has_kind() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void TokenProto::set_has_kind() {
  _has_bits_[0] |= 0x00000004u;
}
inline void TokenProto::clear_has_kind() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void TokenProto::clear_kind() {
  if (kind_ != &::google::protobuf::internal::kEmptyString) {
    kind_->clear();
  }
  clear_has_kind();
}
inline const ::std::string& TokenProto::kind() const {
  return *kind_;
}
inline void TokenProto::set_kind(const ::std::string& value) {
  set_has_kind();
  if (kind_ == &::google::protobuf::internal::kEmptyString) {
    kind_ = new ::std::string;
  }
  kind_->assign(value);
}
inline void TokenProto::set_kind(const char* value) {
  set_has_kind();
  if (kind_ == &::google::protobuf::internal::kEmptyString) {
    kind_ = new ::std::string;
  }
  kind_->assign(value);
}
inline void TokenProto::set_kind(const char* value, size_t size) {
  set_has_kind();
  if (kind_ == &::google::protobuf::internal::kEmptyString) {
    kind_ = new ::std::string;
  }
  kind_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TokenProto::mutable_kind() {
  set_has_kind();
  if (kind_ == &::google::protobuf::internal::kEmptyString) {
    kind_ = new ::std::string;
  }
  return kind_;
}
inline ::std::string* TokenProto::release_kind() {
  clear_has_kind();
  if (kind_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = kind_;
    kind_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void TokenProto::set_allocated_kind(::std::string* kind) {
  if (kind_ != &::google::protobuf::internal::kEmptyString) {
    delete kind_;
  }
  if (kind) {
    set_has_kind();
    kind_ = kind;
  } else {
    clear_has_kind();
    kind_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// required string service = 4;
inline bool TokenProto::has_service() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void TokenProto::set_has_service() {
  _has_bits_[0] |= 0x00000008u;
}
inline void TokenProto::clear_has_service() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void TokenProto::clear_service() {
  if (service_ != &::google::protobuf::internal::kEmptyString) {
    service_->clear();
  }
  clear_has_service();
}
inline const ::std::string& TokenProto::service() const {
  return *service_;
}
inline void TokenProto::set_service(const ::std::string& value) {
  set_has_service();
  if (service_ == &::google::protobuf::internal::kEmptyString) {
    service_ = new ::std::string;
  }
  service_->assign(value);
}
inline void TokenProto::set_service(const char* value) {
  set_has_service();
  if (service_ == &::google::protobuf::internal::kEmptyString) {
    service_ = new ::std::string;
  }
  service_->assign(value);
}
inline void TokenProto::set_service(const char* value, size_t size) {
  set_has_service();
  if (service_ == &::google::protobuf::internal::kEmptyString) {
    service_ = new ::std::string;
  }
  service_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* TokenProto::mutable_service() {
  set_has_service();
  if (service_ == &::google::protobuf::internal::kEmptyString) {
    service_ = new ::std::string;
  }
  return service_;
}
inline ::std::string* TokenProto::release_service() {
  clear_has_service();
  if (service_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = service_;
    service_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void TokenProto::set_allocated_service(::std::string* service) {
  if (service_ != &::google::protobuf::internal::kEmptyString) {
    delete service_;
  }
  if (service) {
    set_has_service();
    service_ = service;
  } else {
    clear_has_service();
    service_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// GetDelegationTokenRequestProto

// required string renewer = 1;
inline bool GetDelegationTokenRequestProto::has_renewer() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GetDelegationTokenRequestProto::set_has_renewer() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GetDelegationTokenRequestProto::clear_has_renewer() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GetDelegationTokenRequestProto::clear_renewer() {
  if (renewer_ != &::google::protobuf::internal::kEmptyString) {
    renewer_->clear();
  }
  clear_has_renewer();
}
inline const ::std::string& GetDelegationTokenRequestProto::renewer() const {
  return *renewer_;
}
inline void GetDelegationTokenRequestProto::set_renewer(const ::std::string& value) {
  set_has_renewer();
  if (renewer_ == &::google::protobuf::internal::kEmptyString) {
    renewer_ = new ::std::string;
  }
  renewer_->assign(value);
}
inline void GetDelegationTokenRequestProto::set_renewer(const char* value) {
  set_has_renewer();
  if (renewer_ == &::google::protobuf::internal::kEmptyString) {
    renewer_ = new ::std::string;
  }
  renewer_->assign(value);
}
inline void GetDelegationTokenRequestProto::set_renewer(const char* value, size_t size) {
  set_has_renewer();
  if (renewer_ == &::google::protobuf::internal::kEmptyString) {
    renewer_ = new ::std::string;
  }
  renewer_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* GetDelegationTokenRequestProto::mutable_renewer() {
  set_has_renewer();
  if (renewer_ == &::google::protobuf::internal::kEmptyString) {
    renewer_ = new ::std::string;
  }
  return renewer_;
}
inline ::std::string* GetDelegationTokenRequestProto::release_renewer() {
  clear_has_renewer();
  if (renewer_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = renewer_;
    renewer_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void GetDelegationTokenRequestProto::set_allocated_renewer(::std::string* renewer) {
  if (renewer_ != &::google::protobuf::internal::kEmptyString) {
    delete renewer_;
  }
  if (renewer) {
    set_has_renewer();
    renewer_ = renewer;
  } else {
    clear_has_renewer();
    renewer_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// -------------------------------------------------------------------

// GetDelegationTokenResponseProto

// optional .hadoop.common.TokenProto token = 1;
inline bool GetDelegationTokenResponseProto::has_token() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GetDelegationTokenResponseProto::set_has_token() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GetDelegationTokenResponseProto::clear_has_token() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GetDelegationTokenResponseProto::clear_token() {
  if (token_ != NULL) token_->::hadoop::common::TokenProto::Clear();
  clear_has_token();
}
inline const ::hadoop::common::TokenProto& GetDelegationTokenResponseProto::token() const {
  return token_ != NULL ? *token_ : *default_instance_->token_;
}
inline ::hadoop::common::TokenProto* GetDelegationTokenResponseProto::mutable_token() {
  set_has_token();
  if (token_ == NULL) token_ = new ::hadoop::common::TokenProto;
  return token_;
}
inline ::hadoop::common::TokenProto* GetDelegationTokenResponseProto::release_token() {
  clear_has_token();
  ::hadoop::common::TokenProto* temp = token_;
  token_ = NULL;
  return temp;
}
inline void GetDelegationTokenResponseProto::set_allocated_token(::hadoop::common::TokenProto* token) {
  delete token_;
  token_ = token;
  if (token) {
    set_has_token();
  } else {
    clear_has_token();
  }
}

// -------------------------------------------------------------------

// RenewDelegationTokenRequestProto

// required .hadoop.common.TokenProto token = 1;
inline bool RenewDelegationTokenRequestProto::has_token() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RenewDelegationTokenRequestProto::set_has_token() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RenewDelegationTokenRequestProto::clear_has_token() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RenewDelegationTokenRequestProto::clear_token() {
  if (token_ != NULL) token_->::hadoop::common::TokenProto::Clear();
  clear_has_token();
}
inline const ::hadoop::common::TokenProto& RenewDelegationTokenRequestProto::token() const {
  return token_ != NULL ? *token_ : *default_instance_->token_;
}
inline ::hadoop::common::TokenProto* RenewDelegationTokenRequestProto::mutable_token() {
  set_has_token();
  if (token_ == NULL) token_ = new ::hadoop::common::TokenProto;
  return token_;
}
inline ::hadoop::common::TokenProto* RenewDelegationTokenRequestProto::release_token() {
  clear_has_token();
  ::hadoop::common::TokenProto* temp = token_;
  token_ = NULL;
  return temp;
}
inline void RenewDelegationTokenRequestProto::set_allocated_token(::hadoop::common::TokenProto* token) {
  delete token_;
  token_ = token;
  if (token) {
    set_has_token();
  } else {
    clear_has_token();
  }
}

// -------------------------------------------------------------------

// RenewDelegationTokenResponseProto

// required uint64 newExpiryTime = 1;
inline bool RenewDelegationTokenResponseProto::has_newexpirytime() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void RenewDelegationTokenResponseProto::set_has_newexpirytime() {
  _has_bits_[0] |= 0x00000001u;
}
inline void RenewDelegationTokenResponseProto::clear_has_newexpirytime() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void RenewDelegationTokenResponseProto::clear_newexpirytime() {
  newexpirytime_ = GOOGLE_ULONGLONG(0);
  clear_has_newexpirytime();
}
inline ::google::protobuf::uint64 RenewDelegationTokenResponseProto::newexpirytime() const {
  return newexpirytime_;
}
inline void RenewDelegationTokenResponseProto::set_newexpirytime(::google::protobuf::uint64 value) {
  set_has_newexpirytime();
  newexpirytime_ = value;
}

// -------------------------------------------------------------------

// CancelDelegationTokenRequestProto

// required .hadoop.common.TokenProto token = 1;
inline bool CancelDelegationTokenRequestProto::has_token() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CancelDelegationTokenRequestProto::set_has_token() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CancelDelegationTokenRequestProto::clear_has_token() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CancelDelegationTokenRequestProto::clear_token() {
  if (token_ != NULL) token_->::hadoop::common::TokenProto::Clear();
  clear_has_token();
}
inline const ::hadoop::common::TokenProto& CancelDelegationTokenRequestProto::token() const {
  return token_ != NULL ? *token_ : *default_instance_->token_;
}
inline ::hadoop::common::TokenProto* CancelDelegationTokenRequestProto::mutable_token() {
  set_has_token();
  if (token_ == NULL) token_ = new ::hadoop::common::TokenProto;
  return token_;
}
inline ::hadoop::common::TokenProto* CancelDelegationTokenRequestProto::release_token() {
  clear_has_token();
  ::hadoop::common::TokenProto* temp = token_;
  token_ = NULL;
  return temp;
}
inline void CancelDelegationTokenRequestProto::set_allocated_token(::hadoop::common::TokenProto* token) {
  delete token_;
  token_ = token;
  if (token) {
    set_has_token();
  } else {
    clear_has_token();
  }
}

// -------------------------------------------------------------------

// CancelDelegationTokenResponseProto


// @@protoc_insertion_point(namespace_scope)

}  // namespace common
}  // namespace hadoop

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_Security_2eproto__INCLUDED