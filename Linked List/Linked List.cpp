// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

//creating a Node class
class Node{
    public:
    int data;
    Node *next;
    
    //constructor-->builds itself on its wn everytime
    Node(int data){
        this->data=data;
        this->next=NULL;//next pointer points to NULL for the time being
    }
    
    //destructor
    ~Node(){
        int value=this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for the node with data "<<value<<endl;
    }
};

void insertAtHead(Node* &head,int d){
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void print(Node* head){
    //base case
    if(head==NULL){
        cout<<"The list is empty "<<endl;
        return ;
    }
    
    //take a temp node to traverse the linked list
    Node* temp=head;//pointing on the node as the head
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;//take temp pointer to the next node
    }
    cout<<endl;
}


void insertAtPosition(Node* &head,Node* &tail, int position, int d){
    //insert at Start
    if(position==1){
        Node *temp=new Node(d);
        temp->next=head;
        head=temp;
        return ;
    }
    
    Node *temp=head;
    int count=1;
    
    while(count<position-1){
        temp=temp->next;
        count++;
    }
    //inserting at the last
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return ;
    }
    
    Node *nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

void deleteNode(int position, Node* head){
    //deleting first or start node
    if(position==1){
        Node *temp=head;
        head=head->next;
        
        //memory free 
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any middle node or last node
        Node *curr=head;
        Node *prev=NULL;
        
        int count=1;//linked list is always 1 based indexing
        while(count<position){
            prev=prev;
            curr=curr->next;
            count++;
        }
        
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

bool isCircular(Node *head){
    //empty list
    if(head==NULL){
        return true;
    }
    
    Node *temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;
}

bool detectLoop(Node *head){
    if(head==NULL){
        return false;
    }
    
    map<Node*,bool> visited;
    Node *temp=head;//pointer to traverse the whole lonked list
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<"Loop is present on the element "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

Node *floydDetectLoop(Node *head){
    if(head==NULL){
        return NULL;
    }
    Node *slow=head;
    Node *fast=head;
    
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        
        //if ever the fast and the slow pointer meets, means that the linked list has a loop
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}

Node* getStartingNode(Node *head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection=floydDetectLoop(head);
    Node* slow=head;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}

void removeLoop(Nod *head){
    if(head==NULL){
        return ;
    }
    Node *startOfLoop=getStartingLoop(head);
    Node *temp=startOfLoop;
    
    while(temp->next!=startOfLoop){
        temp=tem->next;
    }
    temp->next=NULL;
}

int main() {
    //create a new node
    Node *node1=new Node(10);//new node with data=10
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;
    
    //head pointed on node 1
    Node* head=node1;
    Node* tail=node1;//currently on the same node as the head
    
    insertAtTail(tail,12);
    // print(head);
    insertAtTail(tail,15);
    // print(head);

    return 0;
}
