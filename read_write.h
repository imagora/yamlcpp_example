// Copyright (c) 2018 winking324
//


#pragma once  // NOLINT(build/header_guard)


#include <yaml-cpp/yaml.h>


namespace yamlcpp_example {


class ReadWrite {
 public:
  void ReadYaml();

  void WriteYaml();

  void YamlTraversal();

 private:
  void OutputJson(const YAML::Node &root, const std::string &pre);
};


}  // namespace yamlcpp_example

