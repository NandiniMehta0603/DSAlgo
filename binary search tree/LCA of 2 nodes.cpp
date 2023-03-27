#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
//the left subtree returns true
//the right subtree returns true
//at node where both left and right are == true, return that node
//else move forward to prev node

//to every node, there are 2 values associated, a right one and a left one


TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
	//base case
    TreeNode<int> *ans=root;
    if(root==NULL){
        return root;
    }
    
    if(root->data>P->data && root->data>Q->data){
        return LCAinaBST(root->left,P,Q);
    }
    else if(root->data<P->data && root->data<Q->data){
        return LCAinaBST(root->right,P,Q);
    }
    else if(root->data>P->data && root->data<Q->data || root->data<P->data && root->data>Q->data){
        ans=root;
    }
    return ans;
}
