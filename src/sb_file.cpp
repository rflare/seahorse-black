#include <sb_file.h>

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

std::string readFileToString(std::string path) {
    std::ifstream file; 
    file.open(path);

    std::stringstream fileStream;
    fileStream << file.rdbuf();
    file.close(); 

    std::string output = fileStream.str();
    return output;


}
