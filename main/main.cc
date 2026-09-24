#include <iostream>

#include "lib/greeter.h"

int main(int argc, char** argv) {
  std::string name = argc > 1 ? argv[1] : "world";
  std::cout << Greet(name) << std::endl;
  return 0;
}
