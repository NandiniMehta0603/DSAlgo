/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

//steps: make 3 different lists
// 1 of 0s,1 of 1s and 1 of 2s

Node* sortList(Node *head)
{
    Node *zeroHead=new Node(-1);
    Node *zeroTail=zeroHead;
    Node *oneHead=new Node(-1);
    Node *oneTail=oneHead;
    Node *twoHead=new Node(-1);
    Node *twoTail=twoHead;

    Node *temp=head;//to traverse the whole list
    while(temp!=NULL){
        if(temp->data==0){
            zeroTail->next=temp;
            zeroTail=temp;
        }
        else if(temp->data==1){
            oneTail->next=temp;
            oneTail=temp;
        }
        else if(temp->data==2){
            twoTail->next=temp;
            twoTail=temp;
        }
        temp=temp->next;
    }

    if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
        oneTail->next=twoHead->next;
    }else{
        zeroTail->next=twoHead->next;
    }
    twoTail->next=NULL;
    head=zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
    
}
