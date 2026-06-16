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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> values;

        for(ListNode* lst : lists){
            while(lst){
                values.push_back(lst->val);
                lst = lst->next;
            }
        }

        sort(values.begin(), values.end());

        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        for(int node : values){
            curr->next  = new ListNode(node);
            curr = curr->next;
        }

        return res->next;
    }
};
