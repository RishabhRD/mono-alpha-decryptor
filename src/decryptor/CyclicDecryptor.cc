#include "CyclicDecryptor.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

CyclicDecryptor::CyclicDecryptor(Encryptor &encryptor) {
  const std::string rawMessage = "abcdefghijklmnopqrstuvwxyz";
  const std::string encryptedMessage = encryptor.encrypt(rawMessage);
  auto size = rawMessage.size();
  // TODO: Get the way to not use raw loops change
  for (int i = 0; i < size; i++) {
    charMapping[encryptedMessage[i]] = rawMessage[i];
  }
}

std::string CyclicDecryptor::decrypt(const std::string &str) const {
  std::string decryptedMessage = "";
  auto getDecryptedChar = [this](char c) {
    if (!isValidChar(c)) {
      throw std::invalid_argument(std::string("Character not in range : ") + c);
    }
    return charMapping.at(c);
  };
  std::transform(str.begin(), str.end(), std::back_inserter(decryptedMessage),
                 getDecryptedChar);
  return decryptedMessage;
}

bool CyclicDecryptor::isValidChar(char c) const noexcept {
  return c >= 'a' && c <= 'z';
}
