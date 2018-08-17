// Copyright (c) 2018 winking324
//


#include "read_write.h"
#include <iostream>


namespace yamlcpp_example {

void ReadWrite::ReadYaml() {
}

void ReadWrite::WriteYaml() {
  YAML::Node root;
  root["name"] = "Tom";
  root["age"] = 29;
  root["weight"] = 65.2;
  root["height"] = 175;

  YAML::Node children(YAML::NodeType::Sequence);
  children.push_back("Bob");
  children.push_back("Alice");
  root["children"] = children;

  YAML::Emitter emitter;
  emitter << root;
  std::cout << emitter.c_str();
}

void ReadWrite::YamlTraversal() {
  YAML::Node root;
  root["name"] = "Tom";
  root["age"] = 29;
  root["weight"] = 65.2;
  root["height"] = 175;

  YAML::Node children(YAML::NodeType::Sequence);
  YAML::Node child_bob;
  child_bob["name"] = "Bob";
  child_bob["age"] = 3;
  children.push_back(child_bob);

  YAML::Node child_alice;
  child_alice["name"] = "Alice";
  child_alice["age"] = 1;
  children.push_back(child_alice);

  root["children"] = children;

  YAML::Node children_name(YAML::NodeType::Sequence);
  children_name.push_back("Bob");
  children_name.push_back("Alice");
  root["children_name"] = children_name;

  OutputJson(root, "");
}

void ReadWrite::OutputJson(const YAML::Node &root, const std::string &pre) {
  if (!root.IsMap()) {
    std::cout << pre << root.as<std::string>() << ",\n";
    return;
  }

  std::cout << pre << "{\n";
  for (auto iter = root.begin(); iter != root.end(); ++iter) {
    std::cout << pre << "\t\"" << iter->first.as<std::string>() << "\": ";
    if (iter->second.IsMap()) {
      OutputJson(iter->second, "\t\t");
    } else if (iter->second.IsSequence()) {
      std::cout << pre << "[\n";
      for (auto seq_iter = iter->second.begin(); seq_iter != iter->second.end(); ++seq_iter) {
        OutputJson(*seq_iter, "\t\t");
      }
      std::cout << pre << "\t],\n";
    } else {
      std::cout << iter->second.as<std::string>() << ",\n";
    }
  }
  std::cout << pre << "},\n";
}

}  // namespace yamlcpp_example

