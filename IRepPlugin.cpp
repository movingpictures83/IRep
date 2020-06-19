#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "IRepPlugin.h"

void IRepPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

}


void IRepPlugin::run() {}

void IRepPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
 myCommand += "iRep -f "+parameters["target"]+" -o "+file+" -ff -s "+parameters["sample1"]+" "+parameters["sample2"];
 std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<IRepPlugin> IRepPluginProxy = PluginProxy<IRepPlugin>("IRep", PluginManager::getInstance());
