#include "huffman.h"
#include <queue>
#include <memory>
#include <stdexcept>
#include <unordered_map>

using namespace std;

struct Node{
    char ch;
    int freq;
    unique_ptr<Node> left, right;

    Node(char ch, int freq, unique_ptr<Node> left = nullptr, unique_ptr<Node> right = nullptr)
        : ch(ch), freq(freq), left(move(left)), right(move(right)){}
};

struct Compare{
    bool operator()(const unique_ptr<Node>& l, const unique_ptr<Node>& r) {
        return l->freq > r->freq;
    }
};

unique_ptr<Node> buildHuffmanTree(const string& text){
    if (text.empty()){
        throw invalid_argument("Input text cannot be empty");
    }

    unordered_map<char, int> freq;
    for (char ch : text){
        freq[ch]++;
    }

    priority_queue<unique_ptr<Node>, vector<unique_ptr<Node>>, Compare> pq;

    for (const auto& pair : freq){
        pq.push(make_unique<Node>(pair.first, pair.second));
    }

    while (pq.size() > 1){
        auto left = move(const_cast<unique_ptr<Node>&>(pq.top())); 
        pq.pop();
        auto right = move(const_cast<unique_ptr<Node>&>(pq.top()));
        pq.pop();

        int sum = left->freq + right->freq;
        pq.push(make_unique<Node>('\0', sum, move(left), move(right)));
    }

    return move(const_cast<unique_ptr<Node>&>(pq.top()));
}

void buildHuffmanCodes(const Node* root, string code, unordered_map<char, string>& huffmanCodes){
    if (root == nullptr) return;

    if (!root->left && !root->right){
        if (root->ch != '\0'){
            huffmanCodes[root->ch] = code;
        }
    }

    buildHuffmanCodes(root->left.get(), code + "0", huffmanCodes);
    buildHuffmanCodes(root->right.get(), code + "1", huffmanCodes);
}

string huffmanEncode(const string& text){
    auto root = buildHuffmanTree(text);
    unordered_map<char, string> huffmanCodes;
    buildHuffmanCodes(root.get(), "", huffmanCodes);
    
    string encodedText;
    for (char ch : text){
        encodedText += huffmanCodes[ch];
    }
    return encodedText;
}

double huffmanCompRatio(const string& original, const string& encoded){
    if (original.empty() || encoded.empty()){
        return 0.0;
    }
    return (original.size() * 8.0) / encoded.size();
}
