#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// Kompresi menggunakan algoritma Huffman
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

struct compare
{
    bool operator()(Node *l, Node *r)
    {
        // highest priority item has lowest frequency
        return l->freq > r->freq;
    }
};

// Untuk membangun pohon Huffman, kita menggunakan priority queue (min-heap) yang menyimpan node-node berdasarkan frekuensi karakter.
void encode(Node *root, string str,
            unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    // found a leaf node
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}
void decode(Node *root, int &index, string str)
{
    if (root == nullptr)
    {
        return;
    }

    // ketemu leaf node
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}
void buatTree(priority_queue<Node *, vector<Node *>, compare> &pq)
{
    while (pq.size() > 1)
    {
        // Remove the two nodes of highest priority
        // (lowest frequency) from the queue
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // Create a new internal node with these two nodes
        // as children and with frequency equal to the sum
        // of the two nodes' frequencies. Add the new node
        // to the priority queue.
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }
}
void buatQueue(const unordered_map<char, int> &freq, priority_queue<Node *, vector<Node *>, compare> &pq)
{
    for (auto pair : freq)
    {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
}
void hitungFrekuensi(string text, unordered_map<char, int> &freq)
{
    for (char huruf : text)
    {
        freq[huruf]++;
    }
}
void huffmanCodes(const unordered_map<char, string> &huffmanCode)
{
    cout << "Huffman Codes are :\n"
         << '\n';
    for (auto pair : huffmanCode)
    {
        cout << pair.first << " " << pair.second << '\n';
    }
}

void HuffmanTree(string text)
{
    unordered_map<char, int> freq;
    hitungFrekuensi(text, freq);
    priority_queue<Node *, vector<Node *>, compare> pq;
    buatQueue(freq, pq);

    if (pq.empty())
    {
        cout << "Input string kosong.\n";
        return;
    }

    buatTree(pq);

    // root stores pointer to root of Huffman Tree
    Node *root = pq.top();

    // Laksanakan algoritma Huffman untuk menghasilkan kode Huffman untuk setiap karakter dan menyimpannya dalam sebuah map (unordered_map) yang mengaitkan karakter dengan kode biner yang dihasilkan.
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    // print huffman codes
    huffmanCodes(huffmanCode);

    cout << "\nOriginal string was :\n"
         << text << '\n';

    // print encoded string
    string str = "";
    for (char ch : text)
    {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string is :\n"
         << str << '\n';

    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < (int)str.size() - 2)
    {
        decode(root, index, str);
    }
}

int main()
{
    string text = R"(Kampus terbaik inspirasi
tebarkan harapan
Kampus terbaik inovasi wujudkan impian
Kampus terbaik integritas kuatkan tujuan
Kampus terbaik beri terbaik
untuk negeri, untuk dunia
Umat manusia dan alam semesta

Mari bersama hadirkan masa depan
Dalam langkah dan pikiran
agar selalu terdepan
Berbekal ilmu dan jiwa pengabdian
Deras arus zaman tak kan tertahan
Majulah melangkah
Oh Majulah

Kampus terbaik inspirasi
tebarkan harapan
Kampus terbaik inovasi wujudkan impian
Kampus terbaik integritas kuatkan tujuan
Kampus terbaik beri terbaik
untuk negeri, untuk dunia
Umat manusia dan alam semesta

Mari bersama hadirkan masa depan
Dalam langkah dan pikiran
agar selalu terdepan
Berbekal ilmu dan jiwa pengabdian
Deras arus zaman tak kan tertahan
Majulah melangkah

Oh Majulah

Terus berpacu dalam keunggulan
Lincah pembelajar tuk kehidupan
Inilah semangat baru
Tekad raih kesempatan
Wujudkan Kampus Terbaik Selamanya
Hu….

Mari bersama hadirkan masa depan
Dalam langkah dan pikiran
agar selalu terdepan
Berbekal ilmu dan jiwa pengabdian
Deras arus zaman tak kan tertahan
Majulah melangkah

Mari bersama hadirkan masa depan
Dalam langkah dan pikiran
agar selalu terdepan
Berbekal ilmu dan jiwa pengabdian
Deras arus zaman tak kan tertahan
Majulah melangkah
Oh Majulah

Wujudkan Kampus Terbaik Selamanya
Wujudkan Kampus Terbaik Selamanya
Wujudkan Kampus Terbaik Selamanya
Wujudkan Kampus Terbaik Selamanya….)";

    HuffmanTree(text);

    return 0;
}