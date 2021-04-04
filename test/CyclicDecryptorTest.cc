#include "CyclicDecryptor.h"
#include "CyclicEncryptor.h"
#include "defines.h"
#include <catch2/catch.hpp>

tc("CyclicDecryptor decrypts the string with detecting mapping") {
  CyclicEncryptor encryptor(2);
  CyclicDecryptor decryptor(encryptor);
  sec("decryption of encrypted letter should be same") {
    req(decryptor.decrypt(encryptor.encrypt("abc")) == "abc");
    req(decryptor.decrypt(encryptor.encrypt("xyz")) == "xyz");
  }
  sec("decryption of non small letter containing words should throw "
      "exception") {
    reqThrows(decryptor.decrypt("ab9"));
    reqThrows(decryptor.decrypt("/bc"));
  }
}
