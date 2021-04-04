#include "CyclicEncryptor.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

CyclicEncryptor::CyclicEncryptor(const int seed) : seed{seed} {
  auto generateEncryptedChar = [n = 0, seed = seed]() mutable {
    auto encryptedChar = 'a' + n + seed;
    if (encryptedChar > 'z') {
      encryptedChar = (encryptedChar % 'z') + 'a' - 1;
    }
    n++;
    return encryptedChar;
  };
  std::generate(charMapping.begin(), charMapping.end(), generateEncryptedChar);
}

char CyclicEncryptor::getMappingFor(char c) const {
  if (!isValidChar(c)) {
    throw std::invalid_argument(std::string("Character not in range : ") + c);
  }
  return charMapping.at(c - 'a');
}

std::string CyclicEncryptor::encrypt(const std::string &str) const {
  std::string result = "";
  auto pushResultCharToString = [this, &result](char c) {
    char encryptedChar = getMappingFor(c);
    result.push_back(encryptedChar);
  };
  std::for_each(str.begin(), str.end(), pushResultCharToString);
  return result;
}
