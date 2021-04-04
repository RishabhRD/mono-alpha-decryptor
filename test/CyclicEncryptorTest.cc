#include "CyclicEncryptor.h"
#include <catch2/catch.hpp>
#include "defines.h"

tc("CyclicEncryptor encrypts the string with seed cyclically"){
  CyclicEncryptor ceq(2);
  sec("Encryption of letter with forward shifting"){
    std::string init = "abc";
    std::string result = "cde";
    req(ceq.encrypt(init) == result);
    init =  "def";
    result = "fgh";
    req(ceq.encrypt(init) == result);
  }
  sec("Encryption of letter with backward shifting like z to a"){
    std::string init = "xyz";
    std::string result = "zab";
    req(ceq.encrypt(init) == result);
  }
  sec("Encryption of non small letters throw exception"){
    std::string init = "xyzA";
    reqThrows(ceq.encrypt(init));
    init = "xyz1";
    reqThrows(ceq.encrypt(init));
    init = "x/yz";
    reqThrows(ceq.encrypt(init));
  }
}
