#include<queue>
#include<limits.h>

class Node{
    public:
    int data;
    int i;
    int j;

    //constructor
    Node(int data,int row,int col){
        this->data=data;
        this->i=row;
        this->j=col;
    }
};
class operation{
    public:
    bool operator()(Node *a,Node *b){
        return a->data>b->data;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    priority_queue<Node*,vector<Node*>,operation> minHeap;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<k;i++){
        int ele=a[i][0];
        mini=min(mini,ele);
        maxi=max(maxi,ele);
        Node *temp=new Node(ele,i,0);
        minHeap.push(temp);
    }

    int start=mini;
    int end=maxi;
    // int ans=end-start;
    while(minHeap.size()>0){
        Node *temp=minHeap.top();
        minHeap.pop();
        mini=temp->data;
        if(maxi-mini<end-start){
            // ans=maxi-mini;
            start=mini;
            end=maxi;
        }

        int col=temp->j;
        int row=temp->i;
        if(col+1<a[row].size()){
            maxi=max(maxi,a[row][col+1]);
            // mini=min(mini,a[row][col+1]);
            minHeap.push(new Node(a[row][col+1],row,col+1));
        }
        else{
            break;
        }
    }
    return end-start+1;

}
