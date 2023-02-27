// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;
    
    //constructor
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node buildTree(Node *root){
    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    
    if(data==-1){
        return NULL;
    }
    
    cout<<"Enter the data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the data for inserting on the right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(Node *root){
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root){
    //it goes in order LNR
    //base case
    if(root==NULL){
        return ;
    }
    
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node *root){
    //it goes in order NLR
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root){
    //it goes in order LRN
    //base case
    if(root==NULL){
        return
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrderTraversal(Node *root){
    queue<Node *>q;
    cout<<"Enter the value of the root node "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    
    q.push(root);
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        
        cout<<"Enter the value of left node for "<<data<<endl;
        int leftData;
        cin>>leftData;
        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }
        
        cout<<"Enter the value of right node for "<<data<<endl;
        int rightData;
        cin>>rightData;
        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
    
}

int main() {
    node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    /*
    //creating a Tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level order
    cout << "Printing the level order tracersal output " << endl;
    levelOrderTraversal(root);
    cout << "inorder traversal is:  ";
    inorder(root); 
    cout << endl << "preorder traversal is:  ";
    preorder(root); 
    cout << endl << "postorder traversal is:  ";
    postorder(root); 
    */


    return 0;

    return 0;
}
