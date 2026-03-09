#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// Kompresi menggunakan algoritma Huffman
// Langkah pertama adalah menghitung frekuensi kemunculan setiap karakter dalam string input.
// Struktur data yang digunakan adalah Node

// Tiap node punya karakter, frekuensi, dan pointer ke anak kiri dan kanan.
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

Node *getNode(char ch, int freq, Node *left, Node *right)
{
    Node *node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

// Comparison object to be used to order the heap
struct compare
{
    bool operator()(Node *l, Node *r)
    {
        // highest priority item has lowest frequency
        return l->freq > r->freq;
    }
};

void HuffmanTree(string text)
{
    unordered_map<char, int> freq;
    for (char ch : text)
    {
        freq[ch]++;
    }
}