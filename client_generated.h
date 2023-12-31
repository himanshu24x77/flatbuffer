// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CLIENT_H_
#define FLATBUFFERS_GENERATED_CLIENT_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 5 &&
              FLATBUFFERS_VERSION_REVISION == 26,
             "Non-compatible flatbuffers version included");

struct Header;
struct HeaderBuilder;

struct Group;
struct GroupBuilder;

struct Person;
struct PersonBuilder;

enum Gender : uint8_t {
  Gender_Male = 0,
  Gender_Female = 1,
  Gender_MIN = Gender_Male,
  Gender_MAX = Gender_Female
};

inline const Gender (&EnumValuesGender())[2] {
  static const Gender values[] = {
    Gender_Male,
    Gender_Female
  };
  return values;
}

inline const char * const *EnumNamesGender() {
  static const char * const names[3] = {
    "Male",
    "Female",
    nullptr
  };
  return names;
}

inline const char *EnumNameGender(Gender e) {
  if (::flatbuffers::IsOutRange(e, Gender_Male, Gender_Female)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesGender()[index];
}

enum Type : uint16_t {
  Type_Invalid = 0,
  Type_Person = 1,
  Type_Group = 2,
  Type_MIN = Type_Invalid,
  Type_MAX = Type_Group
};

inline const Type (&EnumValuesType())[3] {
  static const Type values[] = {
    Type_Invalid,
    Type_Person,
    Type_Group
  };
  return values;
}

inline const char * const *EnumNamesType() {
  static const char * const names[4] = {
    "Invalid",
    "Person",
    "Group",
    nullptr
  };
  return names;
}

inline const char *EnumNameType(Type e) {
  if (::flatbuffers::IsOutRange(e, Type_Invalid, Type_Group)) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesType()[index];
}

struct Header FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef HeaderBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_MSG_LEN = 4,
    VT_MSG_TYPE = 6
  };
  int32_t msg_len() const {
    return GetField<int32_t>(VT_MSG_LEN, 0);
  }
  bool mutate_msg_len(int32_t _msg_len = 0) {
    return SetField<int32_t>(VT_MSG_LEN, _msg_len, 0);
  }
  Type msg_type() const {
    return static_cast<Type>(GetField<uint16_t>(VT_MSG_TYPE, 0));
  }
  bool mutate_msg_type(Type _msg_type = static_cast<Type>(0)) {
    return SetField<uint16_t>(VT_MSG_TYPE, static_cast<uint16_t>(_msg_type), 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_MSG_LEN, 4) &&
           VerifyField<uint16_t>(verifier, VT_MSG_TYPE, 2) &&
           verifier.EndTable();
  }
};

struct HeaderBuilder {
  typedef Header Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_msg_len(int32_t msg_len) {
    fbb_.AddElement<int32_t>(Header::VT_MSG_LEN, msg_len, 0);
  }
  void add_msg_type(Type msg_type) {
    fbb_.AddElement<uint16_t>(Header::VT_MSG_TYPE, static_cast<uint16_t>(msg_type), 0);
  }
  explicit HeaderBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Header> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Header>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Header> CreateHeader(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    int32_t msg_len = 0,
    Type msg_type = Type_Invalid) {
  HeaderBuilder builder_(_fbb);
  builder_.add_msg_len(msg_len);
  builder_.add_msg_type(msg_type);
  return builder_.Finish();
}

struct Group FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef GroupBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_GROUP_NAME = 4,
    VT_AVERAGE_AGE = 6,
    VT_AVERAGE_WEIGHT = 8,
    VT_NAMES = 10
  };
  const ::flatbuffers::String *group_name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_GROUP_NAME);
  }
  ::flatbuffers::String *mutable_group_name() {
    return GetPointer<::flatbuffers::String *>(VT_GROUP_NAME);
  }
  uint16_t average_age() const {
    return GetField<uint16_t>(VT_AVERAGE_AGE, 0);
  }
  bool mutate_average_age(uint16_t _average_age = 0) {
    return SetField<uint16_t>(VT_AVERAGE_AGE, _average_age, 0);
  }
  float average_weight() const {
    return GetField<float>(VT_AVERAGE_WEIGHT, 0.0f);
  }
  bool mutate_average_weight(float _average_weight = 0.0f) {
    return SetField<float>(VT_AVERAGE_WEIGHT, _average_weight, 0.0f);
  }
  const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *names() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_NAMES);
  }
  ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *mutable_names() {
    return GetPointer<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_NAMES);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_GROUP_NAME) &&
           verifier.VerifyString(group_name()) &&
           VerifyField<uint16_t>(verifier, VT_AVERAGE_AGE, 2) &&
           VerifyField<float>(verifier, VT_AVERAGE_WEIGHT, 4) &&
           VerifyOffset(verifier, VT_NAMES) &&
           verifier.VerifyVector(names()) &&
           verifier.VerifyVectorOfStrings(names()) &&
           verifier.EndTable();
  }
};

struct GroupBuilder {
  typedef Group Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_group_name(::flatbuffers::Offset<::flatbuffers::String> group_name) {
    fbb_.AddOffset(Group::VT_GROUP_NAME, group_name);
  }
  void add_average_age(uint16_t average_age) {
    fbb_.AddElement<uint16_t>(Group::VT_AVERAGE_AGE, average_age, 0);
  }
  void add_average_weight(float average_weight) {
    fbb_.AddElement<float>(Group::VT_AVERAGE_WEIGHT, average_weight, 0.0f);
  }
  void add_names(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> names) {
    fbb_.AddOffset(Group::VT_NAMES, names);
  }
  explicit GroupBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Group> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Group>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Group> CreateGroup(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> group_name = 0,
    uint16_t average_age = 0,
    float average_weight = 0.0f,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> names = 0) {
  GroupBuilder builder_(_fbb);
  builder_.add_names(names);
  builder_.add_average_weight(average_weight);
  builder_.add_group_name(group_name);
  builder_.add_average_age(average_age);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Group> CreateGroupDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *group_name = nullptr,
    uint16_t average_age = 0,
    float average_weight = 0.0f,
    const std::vector<::flatbuffers::Offset<::flatbuffers::String>> *names = nullptr) {
  auto group_name__ = group_name ? _fbb.CreateString(group_name) : 0;
  auto names__ = names ? _fbb.CreateVector<::flatbuffers::Offset<::flatbuffers::String>>(*names) : 0;
  return CreateGroup(
      _fbb,
      group_name__,
      average_age,
      average_weight,
      names__);
}

struct Person FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef PersonBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_AGE = 6,
    VT_WEIGHT = 8,
    VT_GENDER = 10
  };
  const ::flatbuffers::String *name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_NAME);
  }
  ::flatbuffers::String *mutable_name() {
    return GetPointer<::flatbuffers::String *>(VT_NAME);
  }
  uint16_t age() const {
    return GetField<uint16_t>(VT_AGE, 0);
  }
  bool mutate_age(uint16_t _age = 0) {
    return SetField<uint16_t>(VT_AGE, _age, 0);
  }
  float weight() const {
    return GetField<float>(VT_WEIGHT, 0.0f);
  }
  bool mutate_weight(float _weight = 0.0f) {
    return SetField<float>(VT_WEIGHT, _weight, 0.0f);
  }
  Gender gender() const {
    return static_cast<Gender>(GetField<uint8_t>(VT_GENDER, 0));
  }
  bool mutate_gender(Gender _gender = static_cast<Gender>(0)) {
    return SetField<uint8_t>(VT_GENDER, static_cast<uint8_t>(_gender), 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyField<uint16_t>(verifier, VT_AGE, 2) &&
           VerifyField<float>(verifier, VT_WEIGHT, 4) &&
           VerifyField<uint8_t>(verifier, VT_GENDER, 1) &&
           verifier.EndTable();
  }
};

struct PersonBuilder {
  typedef Person Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_name(::flatbuffers::Offset<::flatbuffers::String> name) {
    fbb_.AddOffset(Person::VT_NAME, name);
  }
  void add_age(uint16_t age) {
    fbb_.AddElement<uint16_t>(Person::VT_AGE, age, 0);
  }
  void add_weight(float weight) {
    fbb_.AddElement<float>(Person::VT_WEIGHT, weight, 0.0f);
  }
  void add_gender(Gender gender) {
    fbb_.AddElement<uint8_t>(Person::VT_GENDER, static_cast<uint8_t>(gender), 0);
  }
  explicit PersonBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Person> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Person>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<Person> CreatePerson(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> name = 0,
    uint16_t age = 0,
    float weight = 0.0f,
    Gender gender = Gender_Male) {
  PersonBuilder builder_(_fbb);
  builder_.add_weight(weight);
  builder_.add_name(name);
  builder_.add_age(age);
  builder_.add_gender(gender);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Person> CreatePersonDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    uint16_t age = 0,
    float weight = 0.0f,
    Gender gender = Gender_Male) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  return CreatePerson(
      _fbb,
      name__,
      age,
      weight,
      gender);
}

inline const Header *GetHeader(const void *buf) {
  return ::flatbuffers::GetRoot<Header>(buf);
}

inline const Header *GetSizePrefixedHeader(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<Header>(buf);
}

inline Header *GetMutableHeader(void *buf) {
  return ::flatbuffers::GetMutableRoot<Header>(buf);
}

inline Header *GetMutableSizePrefixedHeader(void *buf) {
  return ::flatbuffers::GetMutableSizePrefixedRoot<Header>(buf);
}

inline bool VerifyHeaderBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Header>(nullptr);
}

inline bool VerifySizePrefixedHeaderBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Header>(nullptr);
}

inline void FinishHeaderBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<Header> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedHeaderBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<Header> root) {
  fbb.FinishSizePrefixed(root);
}

#endif  // FLATBUFFERS_GENERATED_CLIENT_H_
