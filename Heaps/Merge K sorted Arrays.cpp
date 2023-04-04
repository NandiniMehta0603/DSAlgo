#include <bits/stdc++.h> 
#include<queue>
class node{
    public:
    int data;
    int i;
    int j;

    //constructor
    node(int data,int row,int col){
        this->data=data;
        this->i=row;
        this->j=col;
    }
};

class operation{
    public:
    bool operator()(node *a,node *b){
        return a->data>b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // step1: take first elements 
    priority_queue<node*,vector<node*>,operation> mini;
    for(int i=0;i<k;i++){
        node* root=new node(kArrays[i][0],i,0);
        mini.push(root);
    }

    //step2: take out the mini of all and store in ans vector
    vector<int>ans;
    while(mini.size()>0){
        node *temp=mini.top();
        ans.push_back(temp->data);
        mini.pop();

        int row=temp->i;
        int col=temp->j;
        if(col+1<kArrays[row].size()){
            node *temp=new node(kArrays[row][col+1],row,col+1);
            mini.push(temp);
        }
    }
    return ans;
}
