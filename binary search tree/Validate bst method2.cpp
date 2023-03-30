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
bool solve(BinaryTreeNode<int> *root,int mini,int maxi){
    //base case
    if(root==NULL){
        return true;
    }
     if(root->data<=maxi && root->data>=mini){
        bool left=solve(root->left,mini,root->data);
        bool right=solve(root->right,root->data,maxi);
        return left && right;
    }
    else{
        return false;
    }
}

bool validateBST(BinaryTreeNode<int> *root) {
    //step1: denote a max and min limit to each node and then check of the node belongs in that range or not
    int mini=INT_MIN;
    int maxi=INT_MAX;
    return solve(root,mini,maxi);
}
