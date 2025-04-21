//
// Created by Daniel De Oliveira on 4/20/25.
//

#ifndef PROJECT3_2_LZW_H
#define PROJECT3_2_LZW_H

#include <string>
#include <vector>
using namespace std;

string readFileToString(const string& filePath);

vector<int> lzwEncode(string s1);
void lzwDecode(vector<int> op);
double lzwCompRatio(const string& original, const vector<int>& compressed);

#endif //PROJECT3_2_LZW_H
