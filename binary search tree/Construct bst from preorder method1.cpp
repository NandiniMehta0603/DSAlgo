#include <bits/stdc++.h> 
/*
    Following is the class structure of BinaryTreeNode class for referance:

    class BinaryTreeNode {
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
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };
*/
//approach 1: sort preorder to inorder
//construct binary tree from that inorder traversal
BinaryTreeNode<int> *constructbst(int start,int end,vector<int> &preorder){
    //base case
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(preorder[mid]);
    root->left=constructbst(start,mid-1,preorder);
    root->right=constructbst(mid+1,end,preorder);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    //step1: preorder to inorder
    sort(preorder.begin(),preorder.end());//nlogn is the time complexity

    //construct bst from inorder
    return constructbst(0,preorder.size()-1,preorder);
}
