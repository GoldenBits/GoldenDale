#pragma once

//DON'T EDIT - FILE IS GENERATED

#include <string>
#include <vector>
#include <fstream>
#include "json/src/json.hpp"
namespace gen {

class RenderConst {
public:
   class ShaderPaths {
   public:
      static std::string VERTEX_SHADER;
      static std::string FRAGMENT_SHADER;
   };
   class ImagesPaths {
   public:
      static std::string MAIN_MENU_BACKGROUND;
   };
   static void load() {
      std::ifstream fileStream("resources/render.json");
      nlohmann::json dataJson;
      fileStream>>dataJson;
      RenderConst::ShaderPaths::VERTEX_SHADER = dataJson["ShaderPaths"]["VERTEX_SHADER"];
      RenderConst::ShaderPaths::FRAGMENT_SHADER = dataJson["ShaderPaths"]["FRAGMENT_SHADER"];
      RenderConst::ImagesPaths::MAIN_MENU_BACKGROUND = dataJson["ImagesPaths"]["MAIN_MENU_BACKGROUND"];
   }
};
std::string RenderConst::ShaderPaths::VERTEX_SHADER;
std::string RenderConst::ShaderPaths::FRAGMENT_SHADER;
std::string RenderConst::ImagesPaths::MAIN_MENU_BACKGROUND;
}
