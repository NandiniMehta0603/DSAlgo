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
//steps: in order to save some space, do not use a vector
//pred: left subtree mei max ele
//succ: right subtree mei min ele

//find the pred
// void findPred(BinaryTreeNode<int> *root,int &ans){
//     //basically finding the maxi ele in the left subtree
//     //base case
//     if(root->right==NULL){
//         // return root->data;
//         ans=root->data;
//     }
//     if(root==NULL){
//         return ;
//     }

//     if(root->right){
//         findPred(root->right,ans);
//     }
// }
// void findSucc(BinaryTreeNode<int> *root,int &ans){
//     //finding the mini ele in the right subtree
//     //base case
//     if(root->left==NULL){
//         ans=root->data;
//     }
//     if(root==NULL){
//         return ;
//     }
//     if(root->left){
//         findSucc(root->left,ans);
//     }
    
// }


// //first find the key node
// pair<int,int> find(BinaryTreeNode<int> *root,int key){
//     //base case
//     pair<int,int> p=make_pair(-1,-1);
//     if(root==NULL){
//         return p;
//     }
    
//     if(root->data==key){
//         int pred=-1;
//         findPred(root->left,pred);
//         int succ=-1;
//         findSucc(root->right,succ);
//         p.first=pred;
//         p.second=succ;
//     }

//     else if(key<root->data){
//         find(root->left,key);
//     }
//     else if(key>root->data){
//         find(root->right,key);
//     }
//     return p;
// }


pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // pair<int,int> p=find(root,key);
    BinaryTreeNode<int> *temp=root;
    int pred=-1;
    int succ=-1;

    while(temp->data!=key){
        if(temp->data>key){
            succ=temp->data;
            temp=temp->left;
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }
    BinaryTreeNode<int> *leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    BinaryTreeNode<int> *rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    pair<int,int> ans=make_pair(pred,succ);
    return ans;
}

