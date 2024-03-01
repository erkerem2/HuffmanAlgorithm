//--- 2022-2023 Fall Semester Data Structure Assignment 2 ---//
//--------------------------//
//---Name & Surname: Kerem Er
//---Student Number: 820210313
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>

#include "huffman.h"
#include "structs.h"

using namespace std;

//-------------Complete The Functions Below-------------//

//-----------------------------------------------------//
//-----------Reads the key from text file--------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::readKey(const char* argv){
    ifstream readKeyFile;
    readKeyFile.open(argv);

    if(readKeyFile.is_open()){
        while(!readKeyFile.eof()){
            readKeyFile >> key;
        }
    }
    readKeyFile.close();
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//---------Sorts the key in an alpabetic order---------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::sortKey(){
    sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());
};
//-----------------------------------------------------//


//-----------------------------------------------------//
//-------Finds the frequency of the characters---------//
//-----------------------------------------------------//
void Huffman::findFrequency(){
    //DO NOT CHANGE THIS
    sortKey();
    //DO NOT CHANGE THIS
    //Node* head = new Node();
    //queue.enque(head);  

    int len = sortedKey.length();
    int i = 0;

    Node* temp = new Node();
    temp->token.symbol = sortedKey[0];
    temp->token.val = 1;
    
    
    for(i = 0; i < len+1; i++) {

        char test = temp->token.symbol[0];

        if (i == len) {
            queue.enque(temp);
        } else if (i == 0) {
            queue.head = temp;
        } else if (test == sortedKey[i]) {
            temp->token.val += 1;
        } else {

            queue.enque(temp);

            temp = new Node();

            temp->token.symbol = sortedKey[i];
            temp->token.val = 1;
            
        }
    }  
};
//-----------------------------------------------------//


//-----------------------------------------------------//
//----------------Creates Huffman Tree-----------------//
//-----------------------------------------------------//
void Huffman::createHuffmanTree(){
    findFrequency();
    Node* temp1 = queue.head;
    
    Node* temp2 = queue.head->next;

    Node* root_t = new Node();


    while (queue.head->next != NULL){
        
        root_t = huffmanTree.mergeNodes(temp1,temp2);

        root_t->left = temp1;
        root_t->right = temp2;

        if(queue.head->next != NULL) {
            queue.dequeue();
            queue.dequeue();
        }

        queue.enque(root_t);

        temp1 = queue.head;
        temp2 = queue.head->next;


        //queue.enque(root_t);
    }
    
    huffmanTree.root = root_t;
    //huffmanTree.root = queue.head;

};
//-----------------------------------------------------//

//-----------------------------------------------------//
//---------------Prints the Huffman Tree---------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printHuffmanTree(){
    huffmanTree.printTree(huffmanTree.root, 0);
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Finds and returns the binary------------//
//----------------value to given character-------------//
//-----------------------------------------------------//
string Huffman::getTokenBinary(char tokenChar, Node* traverse, string tokenBinary){
    
    char c = tokenChar;
//&& traverse->left != NULL

    if (traverse->left == NULL || traverse->right == NULL) {
        return "";
    }

    if (traverse->left->token.symbol.find(c) != std::string::npos) { 
        
        return "0" + getTokenBinary(c, traverse->left, tokenBinary);

    } else if (traverse->right->token.symbol.find(c) != std::string::npos) {
        
        return "1" + getTokenBinary(c, traverse->right, tokenBinary);

    }

    return "";

};

//-----------------------------------------------------//

//-----------------------------------------------------//
//--------------Encodes the given password-------------//
//-----------------------------------------------------//
void Huffman::encodePassword(string password){

    int len = password.length();
    int i = 0;
    string pass = "";

    string val = "";


    for (i = 0; i < len; i++) {

        pass += getTokenBinary(password[i], huffmanTree.root, pass);
        val += to_string(getTokenBinary(password[i], huffmanTree.root, pass).length());
    }

    encodedValPassword = val;
    encodedBinaryPassword = pass;
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Prints the encoded password-------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printEncodedPassword(){
    cout << "Encoded Password Binary: " << encodedBinaryPassword << endl;
    cout << "Encoded Password Value: " << encodedValPassword << endl;
};

//-----------------------------------------------------//
//--------------Decodes the given password-------------//
//-----------------------------------------------------//
void Huffman::decodePassword(string encodedBinaryPassword, string encodedValPassword){
    findFrequency();
    int len = encodedValPassword.length();
    int h = 0;
    string ans = "";
    string iterate = "";

    int control = 0;

    for (h = 0; h < len; h++) {

        iterate = "";

        char a = encodedValPassword[h];
        int k = (int)(a - '0');
        int i = 0;

        for (i = control; i < k+control; i++) {
            iterate += encodedBinaryPassword[i];
        }

        control += k;

        decodeToken(iterate);

        ans += key; 
    }
    
    decodedPassword = ans;
};

//-----------------------------------------------------//

//-----------------------------------------------------//
//---------------Decodes the given binary--------------//
//-----------------------------------------------------//
void Huffman::decodeToken(string encodedToken){
    //findFrequency();

    Node* temp = queue.head;
    string tokenBinary = "";

    
    while (temp != NULL) {
        if(encodedToken == getTokenBinary(temp->token.symbol[0] , huffmanTree.root, tokenBinary)) {
            key = temp->token.symbol[0];
            return;
        }

        temp = temp->next;

    }
    
    
};
//-----------------------------------------------------//

//-----------------------------------------------------//
//-------------Prints the decoded password-------------//
//------------DO NOT CHANGE THIS FUNCTION--------------//
//-----------------------------------------------------//
void Huffman::printDecodedPassword(){
    cout << "Decoded Password: " << decodedPassword << endl;
};


