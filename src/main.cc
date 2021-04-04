#include "CyclicDecryptor.h"
#include "CyclicEncryptor.h"
#include <iostream>

int main() {
  using namespace std;
  std::string preamble =
      R"(The decryptor assumes a encryptor with one to one mapping of
      characters in range a-z. Other characters would not work and throw
      exceptions A simple cyclic encryptor is provided as proof of concept.
      This cyclic encryptor encrypts the given word in a cyclic fashion. The
      decryptor doesn't assume any concrete implementation just one to one
      mapping)";
  cout << preamble << endl;
  std::cout << "Enter seed to cycle the alphabets: ";
  int seed;
  cin >> seed;
  CyclicEncryptor encryptor(seed);
  CyclicDecryptor decryptor(encryptor);
  cout << "Enter END to end program" << endl;
  while (true) {
    string raw;
    cout << "Enter raw text: ";
    cin >> raw;
    if (raw == "END") {
      break;
    }
    try {
      auto encryptedText = encryptor.encrypt(raw);
      auto decryptedText = decryptor.decrypt(encryptedText);
      cout << "Encrypted text : " << encryptedText << endl;
      cout << "Decrypted text : " << decryptedText << endl;
      cout<<endl<<endl;
    } catch (std::invalid_argument e) {
      cerr << e.what() << endl;
    }
  }
}
