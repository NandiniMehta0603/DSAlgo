#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

//function to count no of leaf nodes
void countLeaf(Node *root,int &count){
    //base case
    if(root==NULL){
        return ;
    }
    
    int left=countLeaf(root->left,count);
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    int right=countLeaf(root->right,count);
}

int count(Node *root){
    int count=0;
    inorder(root,count);
    return count;
}
