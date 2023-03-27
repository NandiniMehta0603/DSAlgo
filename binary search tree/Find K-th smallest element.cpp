#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

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
    };

*************************************************************/
void inorder(BinaryTreeNode<int> *root,vector<int> &temp){
    //base case
    if(root==NULL){
        return ;
    }

    inorder(root->left,temp);
    temp.push_back(root->data);
    inorder(root->right,temp);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    vector<int> temp;
    temp.push_back(-1);
    inorder(root,temp);
    // temp.push_back(-1);
    if(k<temp.size()){
        return temp[k];
    }
    return -1;
}
