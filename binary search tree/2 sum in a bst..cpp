#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
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
    
};
***************/
void inorder(BinaryTreeNode<int> *root,vector<int> &ans){
    //base case
    if(root==NULL){
        return ;
    }

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//steps1: find the inorder traversal
    vector<int> ans;
    inorder(root,ans);

    //step2: take 2 pointers and find the sum
    int i=0;
    int j=ans.size()-1;
    bool result=false;
    while(i<j){
        if(ans[i]+ans[j]==target){
            result=true;
            return result;
        }
        else if(ans[i]+ans[j]>target){
            j--;
        }
        else if(ans[i]+ans[j]<target){
            i++;
        }
    }
    return result;
}
