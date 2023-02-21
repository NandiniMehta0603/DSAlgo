//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//steps: traverse till the middle of the linked list
//reverse the second half of the linked list
//compare the first and second half--> if same then palindrome present else not


class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node *middle(Node *head){
        Node *slow=head;
        Node *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    
    Node *reverse(Node *head){
        Node *prev=NULL;
        Node *curr=head;
        Node *next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head)
    {
        //base case
        if(head->next==NULL){
            return true;
        }
        
        //step1:
        //find middle and traverse till the middle
        Node *mid=middle(head);
        
        //step2: reverse the second half of the linked list
        Node *temp=mid->next;
        mid->next=reverse(temp);
        
        //step3: compare both the halves
        Node *first=head;
        Node *second=mid->next;
        
        while( second!=NULL){
            if(first->data!=second->data){
                return false;
            }
            else{
                first=first->next;
                second=second->next;
            }
        }
        temp=mid->next;
        mid->next=reverse(temp);
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends
