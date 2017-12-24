#pragma once

//DON'T EDIT - FILE IS GENERATED

#include <string>
#include <vector>
#include <fstream>
#include "json/src/json.hpp"
namespace gen {

class Strings {
public:
   static std::string Title;
   static void load() {
      std::ifstream fileStream("resources/strings.json");
      nlohmann::json dataJson;
      fileStream>>dataJson;
      Strings::Title = dataJson["Title"];
   }
};
std::string Strings::Title;
}
