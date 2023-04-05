/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
#include<queue>
class compare{
    public:
    bool operator()(Node<int>* a, Node<int> *b)
    {
        return a->data>b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    //step1: make a min heap and store the first nodes of every heap in the min heap
    
    priority_queue<Node<int>*, vector<Node<int>*>, compare> minHeap;

    int k=listArray.size();
    if(k==0){
        return NULL;
    }
    for(int i=0;i<k;i++){
        if(listArray[i]!=NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node<int> *head=NULL;
    Node<int> *tail=NULL;

    while(minHeap.size()>0)
    {
        Node<int> *top=minHeap.top();
        minHeap.pop();
        if(top->next!=NULL)
        {
            minHeap.push(top->next);
        }
        if(head==NULL)
        {
            //answer ll is empty
            head=top;
            tail=top;
           
        }
        else{
            //insert at linked list
            tail->next=top;
            tail=top;
        }
    }
    return head;
}



