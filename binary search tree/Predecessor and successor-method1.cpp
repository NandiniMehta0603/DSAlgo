#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
//steps:
//find inorder traversal of the binary tree and then find the pred and succ from that inorder

void inorder(BinaryTreeNode<int> * root,vector<int> &temp){
    //base case
    if(root==NULL){
        return ;
    }
    inorder(root->left,temp);
    temp.push_back(root->data);
    inorder(root->right,temp);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    //base case
    if(root==NULL || root->right==NULL && root->left==NULL){
        pair<int,int> p=make_pair(-1,-1);
        return p;
    }

    vector<int> temp;
    temp.push_back(-1);
    inorder(root,temp);
    temp.push_back(-1);

    //find the element
    pair<int,int> p;
    for(int i=0;i<temp.size();i++){
        if(temp[i]==key){
            p.first=temp[i-1];
            p.second=temp[i+1];
            // if(i==0){
            //     p.first=-1;
            //     p.second=temp[i+1];
            // }
            // if(i==temp.size()-1){
            //     p.first=temp[i-1];
            //     p.second=-1;
            // }
            // else{
            //     p.first=temp[i-1];
            //     p.second=temp[i+1];
            // }
        }
    }
    return p;
}
