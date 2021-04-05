# mono-alphabetic-decryptor

![Unit Tests](https://github.com/RishabhRD/mon-alpha-decryptor/actions/workflows/automated_test.yaml/badge.svg)

This is a decryptor that shows a proof of concept of encryption with a secret
key with one-to-one character mapping is not safe.

This project is part of assignment of my ACN course.

This project also serves an example of building a modern c++ project with
cmake and catch2(for testing).

## Installation

```bash
mkdir -p bin
cd bin
cmake ..
make
```

## To run tests
```bash
mkdir -p bin
cd bin
cmake ..
make
make test
```

Or

```bash
mkdir -p bin
cd bin
cmake ..
make
./tests
```
