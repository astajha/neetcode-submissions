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
        ListNode*prev=NULL;
        ListNode*curr=slow;
        while(curr!=NULL){
            ListNode*nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
      ListNode*first=head;
      ListNode*last=prev;
      while(last!=NULL){
        if(first->val!=last->val){
            return false;
        }
            first=first->next;
            last=last->next;
      }
        
        return true;
      

    }
};