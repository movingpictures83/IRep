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
 if (parameters.count("sample1") != 0) {
 myCommand += "iRep -f "+parameters["target"]+" -o "+file+" -ff -s "+parameters["sample1"]+" "+parameters["sample2"];
 myCommand += "iRep -f "+parameters["target"]+" -o "+file+" -ff -s "+parameters["sample1"]+" "+parameters["sample2"];
 }
 else{
//iRep -f GCA_002903045.1_ASM290304v1_genomic.fna -s output.sam -o output-iRep
 myCommand += "iRep -ff -f ";
 std::ifstream infile(PluginManager::addPrefix(parameters["target"]), std::ios::in);
 std::vector<std::string> myfiles;
 std::string onefile;
 while (!infile.eof()) {
    getline(infile, onefile);
    if (onefile.length() != 0)
	    myfiles.push_back(onefile);
 }
 for (int i = 0; i < myfiles.size(); i++){
	 myCommand += PluginManager::addPrefix(myfiles[i]);
	 myCommand += " ";
 }
 myCommand += " -s "+PluginManager::addPrefix(parameters["sample"])+" -o "+file;
 }
 std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<IRepPlugin> IRepPluginProxy = PluginProxy<IRepPlugin>("IRep", PluginManager::getInstance());
