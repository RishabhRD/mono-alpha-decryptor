#include <array>
#include "Encryptor.h"

class CyclicEncryptor : public Encryptor{
  public:
    virtual std::string encrypt(const std::string &str) const override ;
    CyclicEncryptor(const int seed = 0);
  private:
    int seed;
    std::array<char, 26> charMapping;
    char getMappingFor(char c) const;
    bool isValidChar(char c) const noexcept;
};
