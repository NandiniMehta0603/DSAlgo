#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/
//this time, lets use maps to detect loop as its given that all are unique entries in the linked list
bool isCircular(Node* head){
    //base case
    if(head==NULL){
        return true;
    }

    unordered_map<Node*,bool> mp;

    Node *temp=head;//to traverse the linked list
    while(temp!=NULL){
        //if loop is detected
        if(mp[temp]==true){
            return true;
        }
        //else the move forward
        mp[temp]=true;
        temp=temp->next;
    }
    return false;
}
