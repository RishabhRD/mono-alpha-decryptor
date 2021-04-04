#include "CyclicEncryptor.h"
#include <algorithm>

CyclicEncryptor::CyclicEncryptor(const int seed) : seed{seed} {}

char CyclicEncryptor::getMappingFor(char c) { return 'a'; }

std::string CyclicEncryptor::encrypt(const std::string &str) const {
  return "";
}
