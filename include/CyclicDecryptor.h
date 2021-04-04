#include "Decryptor.h"
#include "Encryptor.h"
#include <map>

class CyclicDecryptor : public Decryptor {
public:
  virtual std::string decrypt(const std::string &str) const override;
  CyclicDecryptor(Encryptor &encryptor);

private:
  std::map<char, char> charMapping;
  bool isValidChar(char c) const noexcept;
};
