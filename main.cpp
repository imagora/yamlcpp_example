// Copyright (c) 2018 winking324
//


#include <iostream>

#include "read_write.h"


int main(int argc, char *argv[]) {
  yamlcpp_example::ReadWrite read_write;
  std::cout << "------ Sample: Convert String to Yaml ------\n";
  read_write.ReadYaml();
  std::cout << "\n";

  std::cout << "------ Sample: Convert Yaml to String ------\n";
  read_write.WriteYaml();
  std::cout << "\n";

  std::cout << "------ Sample: Yaml Traversal         ------\n";
  read_write.YamlTraversal();
  std::cout << "\n";

  return 0;
}


