
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_java_security_hash_Sha384__
#define __gnu_java_security_hash_Sha384__

#pragma interface

#include <gnu/java/security/hash/BaseHash.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace java
    {
      namespace security
      {
        namespace hash
        {
            class Sha384;
        }
      }
    }
  }
}

class gnu::java::security::hash::Sha384 : public ::gnu::java::security::hash::BaseHash
{

public:
  Sha384();
private:
  Sha384(::gnu::java::security::hash::Sha384 *);
public:
  static JArray< jlong > * G(jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, JArray< jbyte > *, jint);
  virtual ::java::lang::Object * clone();
public: // actually protected
  virtual void transform(JArray< jbyte > *, jint);
  virtual JArray< jbyte > * padBuffer();
  virtual JArray< jbyte > * getResult();
  virtual void resetContext();
public:
  virtual jboolean selfTest();
private:
  static JArray< jlong > * sha(jlong, jlong, jlong, jlong, jlong, jlong, jlong, jlong, JArray< jbyte > *, jint);
  static JArray< jlong > * k;
  static const jint BLOCK_SIZE = 128;
  static ::java::lang::String * DIGEST0;
  static JArray< jlong > * w;
  static ::java::lang::Boolean * valid;
  jlong __attribute__((aligned(__alignof__( ::gnu::java::security::hash::BaseHash)))) h0;
  jlong h1;
  jlong h2;
  jlong h3;
  jlong h4;
  jlong h5;
  jlong h6;
  jlong h7;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_java_security_hash_Sha384__
