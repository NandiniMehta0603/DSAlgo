#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }   
    };

*************************************************************/
//approach 1: merge the 2 inorder lists, sort them and then make a bst out of the final inorder list
void inorder(TreeNode<int> *root,vector<int> &inorder1){
    //base case
    if(root==NULL){
        return ;
    }
    inorder(root->left,inorder1);
    inorder1.push_back(root->data);
    inorder(root->right,inorder1);
}

TreeNode<int> *constructBst(vector<int> &inorder,int start,int end){
    //base case
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    TreeNode<int> *root=new TreeNode<int>(inorder[mid]);
    root->left=constructBst(inorder,start,mid-1);
    root->right=constructBst(inorder,mid+1,end);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    //step1: find the inorder of tree1 
    vector<int> inorder1;
    inorder(root1,inorder1);

    //inorder of tree 2
    vector<int> inorder2;
    inorder(root2,inorder2);

    //merge both the lists
    for(int i=0;i<inorder2.size();i++){
        inorder1.push_back(inorder2[i]);
    }

    //sort the list
    sort(inorder1.begin(),inorder1.end());

    //build the bst from the inorder
    TreeNode<int> *root=constructBst(inorder1,0,inorder1.size()-1);

    return root;
}
