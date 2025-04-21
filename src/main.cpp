#include <iostream>
#include "huffman.h"
#include "lzw.h"
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

int main() {

//    cout << readFileToString("../data/scientific1.txt") << endl;


    string s = readFileToString("../data/scientific5.txt");
    vector<int> output_code = lzwEncode(s);
    cout << lzwCompRatio(s, output_code) << endl;





//    cout << "Output Codes are: ";
//    for (int i = 0; i < output_code.size(); i++) {
//        cout << output_code[i] << " ";
//    }
//    cout << endl;
//    lzwDecode(output_code);

    return 0;
}
