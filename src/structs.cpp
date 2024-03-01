//--- 2022-2023 Fall Semester Data Structure Assignment 2 ---//
//--------------------------//
//---Name & Surname: Kerem Er
//---Student Number: 820210313
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "structs.h"

using namespace std;

//-------------Complete The Functions Below-------------//

//-------------Initialize Priority Queue-------------//
PriorityQueue::PriorityQueue(){
    Node* head = new Node();
    head->next = NULL;

};

//-------------Insert New Node To Priority Queue-------------//
void PriorityQueue::enque(Node* newnode){
    if(head == NULL){    
    
        head = newnode;

    } else if (newnode->token.val < head->token.val) {
        Node* a = new Node();
        a = newnode; 
        newnode->next = head;
        head = a;

    } else { 
        Node* temp = head;
        int control = 0;


        while (temp->next != NULL) {

            if (newnode->token.val < temp->next->token.val){
                control = 1;
                break;
            }

            temp = temp->next;
        }
        if (control == 1) {
            Node* temp2 = temp->next;
            temp->next = newnode;
            newnode->next = temp2;
            
        } else {
            if (newnode->token.symbol == temp->token.symbol) {
                return;
            }
            
            temp->next = newnode;
        }
    }


};

//-------------Remove Node From Priority Queue-------------//
Node* PriorityQueue::dequeue(){
    Node* temp = head->next;
    head = head->next;
    return temp;
};

//-------------Initialize Tree-------------//
Tree::Tree(){
    root = NULL;
};

//-------------Delete Tree Nodes From Memory-------------//
Tree::~Tree(){
    //deleteTree(root);
};

//-------------Delete Tree From Memory-------------//
void Tree::deleteTree(Node* node){      // K
    //-------------This Function Is Not Necessary-------------//
    //-----------------Use It At Your Own Will----------------//
    /*if (root == NULL) { 
        return;
    }
    
    deleteTree(root->left);
    deleteTree(root->right);
    root == NULL;
    return;*/
}

//-------------Merges Two Node Into One-------------//
Node* Tree::mergeNodes(Node* temp1, Node* temp2){
    Node* temp_M = new Node();

    string a1 = temp1->token.symbol;
    if(temp2 == NULL) {
        return temp_M;
    }
    string a2 = temp2->token.symbol;

    temp_M->token.symbol = a1 + a2;
    temp_M->token.val = temp1->token.val + temp2->token.val;
    
    return temp_M;
};

void Tree::printTree(Node* traverse, int level){
    cout << level << "\t";
    for (int i = 0; i < level; i++)
        cout << "\t"; 

    cout << traverse->token.symbol << "(" << traverse->token.val << ")" << endl;

    if(traverse->left)
        printTree(traverse->left, level + 1);  
    if(traverse->right)
        printTree(traverse->right, level + 1);
};