#include <iostream>
using namespace std;

// Node structure for the Huffman Tree
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// Simple Node array to replace priority queue behavior
void insertSorted(Node* nodes[], int& n, Node* newNode) {
    int i = n - 1;
    while (i >= 0 && nodes[i]->freq > newNode->freq) {
        nodes[i + 1] = nodes[i];
        i--;
    }
    nodes[i + 1] = newNode;
    n++;
}

// Generate Huffman codes by traversing the Huffman Tree
void generateHuffmanCodes(Node* root, string code) {
    if (root == nullptr) return;

    // If we reach a leaf node, print the code for the character
    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << endl;
    }

    // Traverse left and right with '0' and '1' appended to the code
    generateHuffmanCodes(root->left, code + "0");
    generateHuffmanCodes(root->right, code + "1");
}

// Main function to build Huffman Tree and generate codes
void huffmanEncoding(char characters[], int frequencies[], int n) {
    Node* nodes[50];  // Array to store nodes, maximum size of 50
    int nodeCount = 0;

    // Create a node for each character and insert into the sorted array
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node(characters[i], frequencies[i]);
    }
    nodeCount = n;

    // Build the Huffman Tree
    while (nodeCount > 1) {
        Node* left = nodes[0];
        Node* right = nodes[1];

        // Create a new node with the sum of frequencies
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        // Shift nodes in the array and insert the new node in sorted order
        for (int i = 2; i < nodeCount; i++) {
            nodes[i - 2] = nodes[i];
        }
        nodeCount -= 2;

        // Insert the new node in the correct position to maintain order
        insertSorted(nodes, nodeCount, newNode);
    }

    // Generate and print Huffman Codes
    cout << "Huffman Codes for each character:\n";
    generateHuffmanCodes(nodes[0], "");
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    char characters[50];
    int frequencies[50];

    // User input for characters and their frequencies
    for (int i = 0; i < n; i++) {
        cout << "Enter character #" << (i + 1) << ": ";
        cin >> characters[i];
        cout << "Enter frequency of " << characters[i] << ": ";
        cin >> frequencies[i];
    }

    // Call Huffman Encoding function
    huffmanEncoding(characters, frequencies, n);

    return 0;
}
