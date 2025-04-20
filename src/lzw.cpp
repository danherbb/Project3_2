#include "lzw.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

string readFileToString(const string& filePath) {
    ifstream file(filePath, ios::in | ios::binary);
    if (!file.is_open()) {
        throw runtime_error("Could not open file");
    }
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}