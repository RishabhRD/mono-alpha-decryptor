#include <string>

class Decryptor {
public:
  virtual std::string decrypt(const std::string &str) const = 0;
};
