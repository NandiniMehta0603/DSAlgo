/************************************************************

    Following is the linked list node structure.
    
    class Node 
    {
        public:
        int data;
        Node* next;

        Node(int data) 
        {
            this->data = data;
            this->next = NULL;
        }
    };
    
************************************************************/

Node * uniqueSortedList(Node * head) {
    //temp pointer to traverse the whole list
    Node *temp=head;

    while(temp!=NULL){
        if(temp->next->next!=NULL && temp->next->data==temp->data){
            temp->next=temp->next->next;
        }
        else if(temp->next->data==temp->data && temp->next->next==NULL){
            temp->next=NULL;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}
