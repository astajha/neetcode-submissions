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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL||left==right){
            return head;
        }
        int i=1;
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(curr!=NULL&&i!=left){
            prev=curr;
            curr=curr->next;
            i++;
        }
        ListNode*pointToStart=prev;
        ListNode*start=curr;
        prev=NULL;
        while(curr!=NULL&&i!=right+1){
            ListNode*next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        start->next=curr;
        if(pointToStart!=NULL){
            pointToStart->next=prev;
        }else{
            return prev;
        }
    return head;
    }
};