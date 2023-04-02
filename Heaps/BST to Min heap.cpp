#include <iostream>
#include<vector>
using namespace std;

//structure node of the bst
struct Node{
    int data;
    Node *left;
    Node *right;
    
    //constructor
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    
};

void inorderTraversal(Node *root,vector<int> &arr){
    //base case
    if(root==NULL){
        return ;
    }
    
    inorderTraversal(root->left,arr);
    arr.push_back(root->data);
    inorderTraversal(root->right,arr);
}

void BSTtoMinHeap(Node *root,vector<int> arr,int &index){
    //base case
    if(root==NULL){
        return ;
    }
    //traverse in preorder vala order-->NLR
    root->data=arr[index];
    index++;
    BSTtoMinHeap(root->left,arr,index);
    BSTtoMinHeap(root->right,arr,index);
}

void convertToMinHeap(Node *root){
    vector<int> arr;
    
    //inorder traversal
    inorderTraversal(root,arr);
    
    //bst to min convertToMinHeap
    int index=0;
    BSTtoMinHeap(root,arr,index);
}

void preorderTraversal(Node *root){
    if(!root)
        return ;
    
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    struct Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(6);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->left=new Node(5);
    root->right->right=new Node(7);
    
    convertToMinHeap(root);
    
    cout<<"preorder traversal is: "<<endl;
    preorderTraversal(root);
	return 0;
}
