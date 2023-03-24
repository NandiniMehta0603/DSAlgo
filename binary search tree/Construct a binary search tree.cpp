#include<iostream>
using namespace std;

class bst{
    public:
    int data;
    bst *left;
    bst *right;
    
    bst(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    
};
bst *insert(bst *root,int data){
    if(root==NULL){
        root=new bst(data);
    }
    
    if(data>root->data){
        root->right=insert(root->right,data);
    }
    else if(data<root->data){
        root->left=insert(root->left,data);
    }
    
    return root;
}
void takeInput(bst *root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insert(root,data);
        cin>>data;
    }
}
void inorder(bst *root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
int main(){
    bst *root=NULL;
    cout<<"Enter the data to create BTS"<<endl;
    takeInput(root);
    inorder(root);
    return 0;
}
