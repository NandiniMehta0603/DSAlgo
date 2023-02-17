/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
//steps: 1. detect loop
//       2. find the intersection
//       3. remove the loop

Node* DetectLoop(Node *head){
    //base case
    if(head==NULL){
        return head;
    }

    Node *slow=head;
    Node *fast=head;

    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* LoopStarting(Node *head, Node *intersection){
    Node *slow=head;
    Node *LoopStart;
    if(head==NULL){
        return NULL;
    }
    if(intersection==NULL){
        return NULL;
    }
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(Node* &head, Node *LoopStart){
    if(head==NULL){
        return ;
    }
    if(LoopStart==NULL){
        return ;
    }
    
    Node *temp=head;

    while(temp->next!=LoopStart){
        temp=temp->next;
    }
    temp->next=NULL;
}

Node *removeLoop(Node *head)
{

    if(DetectLoop(head)!=NULL){
        Node *intersection=DetectLoop(head);
        Node *LoopStart=LoopStarting(head,intersection);
        removeLoop(head,LoopStart);
    }

    return head;
}
