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
    bool isPalindrome(ListNode* head) {
        ListNode*fast=head;
        ListNode*slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
          
        }
        ListNode*temp=slow;
        ListNode*prev=NULL;
        while(temp!=NULL){
             ListNode*nextnode=temp->next;
             temp->next=prev;
            prev=temp;
            temp=nextnode;
            
        }
        ListNode*first=head;
        ListNode*last=prev;
        while(last!=NULL){
            if(first->val!=last->val){
                return false;
            }
            first = first->next;
            last = last->next;
        }
            return true;
        

    }
};