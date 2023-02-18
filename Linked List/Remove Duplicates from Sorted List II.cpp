/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        //make a dummy pointer
        ListNode *temp=new ListNode(0);
        temp->next=head;
        ListNode *prev=temp;

        //pointer head will traverse the whole list
        while(head!=NULL){
            //same element
            if(head->next!=NULL && head->val==head->next->val){
                while(head->next!=NULL && head->val==head->next->val){
                    head=head->next;
                }
                prev->next=head->next;
                head=prev->next;
            }
            else{
                prev=prev->next;
                head=head->next;//move both pointers ahead
            }
        }
        return temp->next;
    }
};
