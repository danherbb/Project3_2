#include <iostream>
#include "huffman.h"
#include "lzw.h"
using namespace std;

int main() {
    cout << getHello() << endl;
    cout << endl;

    cout << readFileToString("../data/control1.txt") << endl;

    return 0;
}
