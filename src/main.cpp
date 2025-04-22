#include <iostream>
#include "huffman.h"
#include "lzw.h"
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

double vecAvg(vector<double> vec) {
    double avg = 0.0;
    for (double d : vec) avg += d;
    return avg / vec.size();
}

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
    vector<double> lzwFicRatios, hufFicRatios, lzwSciRatios, hufSciRatios;
    string ficPath = "../data/control";
    string sciPath = "../data/scientific";

    string ogStr;
    for (int i = 1; i <= 5; i++) {
        ogStr = readFileToString(ficPath + to_string(i) + ".txt");
        lzwFicRatios.push_back(lzwCompRatio(ogStr, lzwEncode(ogStr)));
        hufFicRatios.push_back(huffmanCompRatio(ogStr, huffmanEncode(ogStr)));

        ogStr = readFileToString(sciPath + to_string(i) + ".txt");
        lzwSciRatios.push_back(lzwCompRatio(ogStr, lzwEncode(ogStr)));
        hufSciRatios.push_back(huffmanCompRatio(ogStr, huffmanEncode(ogStr)));
    }

    cout << "Fiction\t\tLZW\t\t\tHuffman\n";
    cout << "---------------------------------" << endl;
    for (int i = 0; i < 5; i++)
        cout << "  " << i + 1 << "\t\t   " << lzwFicRatios[i] << "\t\t" << hufFicRatios[i] << endl;
    cout << "---------------------------------\n";
    cout << "Average:   " << vecAvg(lzwFicRatios) << "\t\t" << vecAvg(hufFicRatios) << "\n";
    cout << "---------------------------------\n\n\n";

    cout << "Science\t\tLZW\t\t\tHuffman\n";
    cout << "---------------------------------" << endl;
    for (int i = 0; i < 5; i++)
        cout << "  " << i + 1 << "\t\t   " << lzwSciRatios[i] << "\t\t" << hufSciRatios[i] << endl;
    cout << "---------------------------------\n";
    cout << "Average:   " << vecAvg(lzwSciRatios) << "\t\t" << vecAvg(hufSciRatios) << "\n\n";

    return 0;
}
