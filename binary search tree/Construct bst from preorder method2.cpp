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
BinaryTreeNode<int> *constructbst(vector<int> &preorder,int mini,int maxi,int &i){
    //base case
    if(i>=preorder.size()){
        return NULL;
    }

    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }

    BinaryTreeNode<int> *temp=new BinaryTreeNode<int>(preorder[i]);
    i++;
    temp->left=constructbst(preorder,mini,temp->data,i);
    temp->right=constructbst(preorder,temp->data,maxi,i);
    return temp;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int index=0;
    return constructbst(preorder,mini,maxi,index);

}

