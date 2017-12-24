#pragma once

//DON'T EDIT - FILE IS GENERATED

#include <string>
#include <vector>
#include <fstream>
#include "json/src/json.hpp"
namespace gen {

class C {
public:
   class Images {
   public:
      static std::string IMAGES_DIR;
      static std::string MAIN_MENU_BACKGROUND;
      static std::string DEFAULT_DIALOG_BACKGROUND;
      static std::string FLAG;
   };
   class Common {
   public:
      static int WIDTH;
      static int HEIGHT;
      static int FULLSCREEN;
      static float LUCKY;
   };
   class Authors__GENERATED {
   public:
      std::string name;
      std::string description;
      class tablica__GENERATED {
      public:
         int wartosc;
      };
      std::vector<tablica__GENERATED> tablica;
   };
   static std::vector<Authors__GENERATED> Authors;
   static void load() {
      std::ifstream fileStream("resources/config.json");
      nlohmann::json dataJson;
      fileStream>>dataJson;
      C::Images::IMAGES_DIR = dataJson["Images"]["IMAGES_DIR"];
      C::Images::MAIN_MENU_BACKGROUND = dataJson["Images"]["MAIN_MENU_BACKGROUND"];
      C::Images::DEFAULT_DIALOG_BACKGROUND = dataJson["Images"]["DEFAULT_DIALOG_BACKGROUND"];
      C::Images::FLAG = dataJson["Images"]["FLAG"];
      C::Common::WIDTH = dataJson["Common"]["WIDTH"];
      C::Common::HEIGHT = dataJson["Common"]["HEIGHT"];
      C::Common::FULLSCREEN = dataJson["Common"]["FULLSCREEN"];
      C::Common::LUCKY = dataJson["Common"]["LUCKY"];
      for(unsigned int i = 0; i<dataJson["Authors"].size(); i++) {
         C::Authors.push_back(C::Authors__GENERATED());
         C::Authors.at(i).name = dataJson["Authors"].at(i)["name"];
         C::Authors.at(i).description = dataJson["Authors"].at(i)["description"];
         for(unsigned int ii = 0; ii<dataJson["Authors"].at(i)["tablica"].size(); ii++) {
            C::Authors.at(i).tablica.push_back(C::Authors__GENERATED::tablica__GENERATED());
            C::Authors.at(i).tablica.at(ii).wartosc = dataJson["Authors"].at(i)["tablica"].at(ii)["wartosc"];
         }
      }
   }
};
std::string C::Images::IMAGES_DIR;
std::string C::Images::MAIN_MENU_BACKGROUND;
std::string C::Images::DEFAULT_DIALOG_BACKGROUND;
std::string C::Images::FLAG;
int C::Common::WIDTH;
int C::Common::HEIGHT;
int C::Common::FULLSCREEN;
float C::Common::LUCKY;
std::vector<C::Authors__GENERATED> C::Authors;
}
