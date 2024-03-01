
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_management_openmbean_ArrayType__
#define __javax_management_openmbean_ArrayType__

#pragma interface

#include <javax/management/openmbean/OpenType.h>
extern "Java"
{
  namespace javax
  {
    namespace management
    {
      namespace openmbean
      {
          class ArrayType;
          class OpenType;
          class SimpleType;
      }
    }
  }
}

class javax::management::openmbean::ArrayType : public ::javax::management::openmbean::OpenType
{

  static ::java::lang::String * getArrayClassName(::javax::management::openmbean::OpenType *, jint, jboolean);
  static jint getDimensions(::javax::management::openmbean::OpenType *, jint);
  static ::javax::management::openmbean::SimpleType * getPrimitiveType(::java::lang::Class *);
  static ::java::lang::Class * getPrimitiveTypeClass(::javax::management::openmbean::SimpleType *);
  static ::javax::management::openmbean::OpenType * getElementType(::javax::management::openmbean::OpenType *);
  static ::java::lang::String * getElementTypeName(::javax::management::openmbean::OpenType *);
public:
  ArrayType(jint, ::javax::management::openmbean::OpenType *);
  ArrayType(::javax::management::openmbean::SimpleType *, jboolean);
  virtual jboolean equals(::java::lang::Object *);
  static ::javax::management::openmbean::ArrayType * getArrayType(::javax::management::openmbean::OpenType *);
  static ::javax::management::openmbean::ArrayType * getPrimitiveArrayType(::java::lang::Class *);
  virtual jint getDimension();
  virtual ::javax::management::openmbean::OpenType * getElementOpenType();
  virtual jint hashCode();
  virtual jboolean isPrimitiveArray();
  virtual jboolean isValue(::java::lang::Object *);
  virtual ::java::lang::String * toString();
private:
  static const jlong serialVersionUID = 720504429830309770LL;
  jint __attribute__((aligned(__alignof__( ::javax::management::openmbean::OpenType)))) dimension;
  ::javax::management::openmbean::OpenType * elementType;
  jboolean primitiveArray;
  ::java::lang::Integer * hashCode__;
  ::java::lang::String * string;
  static ::java::util::Map * cache;
  static ::java::util::Map * primCache;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_management_openmbean_ArrayType__
