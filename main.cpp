#include <iostream>
#include <string>
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
