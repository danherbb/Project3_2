#ifndef PROJECT3_2_HUFFMAN_H
#define PROJECT3_2_HUFFMAN_H

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> huffmanEncodeToNumbers(const string& text);
string huffmanEncodeToString(const string& text);
double huffmanCompRatio(const string& original, const string& encoded);
double huffmanCompRatio(const string& original, const vector<int>& encoded);

#endif //PROJECT3_2_HUFFMAN_H
