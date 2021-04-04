#include <string>

class Encryptor {
public:
  virtual std::string encrypt(const std::string &str) const = 0;
};
