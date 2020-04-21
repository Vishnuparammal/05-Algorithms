/*
Reference: https://www.geeksforgeeks.org/huffman-decoding/

Input Data : AAAAAABCCCCCCDDEEEEE
Frequencies : A: 6, B: 1, C: 6, D: 2, E: 5
Encoded Data : 
0000000000001100101010101011111111010101010
Huffman Tree: '#' is the special character used
              for internal nodes as character field
              is not needed for internal nodes. 
               #(20)
             /       \
        #(12)         #(8)
     /      \        /     \
    A(6)     C(6) E(5)     #(3)
                         /     \
                       B(1)    D(2)  
Code of 'A' is '00', code of 'C' is '01', ..
Decoded Data : AAAAAABCCCCCCDDEEEEE


Input Data : GeeksforGeeks
Character With there Frequencies
e 10, f 1100, g 011, k 00, o 010, r 1101, s 111
Encoded Huffman data :
01110100011111000101101011101000111
Decoded Huffman Data
geeksforgeeks
*/

#include<iostream>
using namespace std;

class Node{
    public:
        char data;
        Node* left;
        Node* right;
        Node(){}
        Node(char x){
            data = x;
            left = NULL;
            right = NULL;
        }
};

void decode_huff(Node* root, string s){
    Node* temp = new Node;
    temp = root;
    int i=0;
    while(i<s.length()){
        // traverse a node as per given string
        if (s[i]=='0' && temp->left){
            temp = temp->left;
            i++;
        }
        else if (s[i]=='1' && temp->right){
            temp = temp->right;
            i++;
        }
        else{
            cout<<-1;
        }

        // check if current node is a leaf
        // in that case this is our decoded character
        if (!temp->left && !temp->right){
            cout<<temp->data;
            temp = root;
        }
    }
    delete temp;
}

int main(){

    // Assume that a huffman tree has been given
    Node* root = new Node('x');
    root->left = new Node('x');
    root->right = new Node('A');
    root->left->left = new Node('B');
    root->left->right = new Node('C');

    // Encoded huffman string
    string s = "1001011";

    decode_huff(root, s);

    return 0;
}