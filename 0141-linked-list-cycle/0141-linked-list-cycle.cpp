/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)return false;
        if(head->next->next==head)return true; 
        ListNode* fast=head->next->next,*slow=head->next;
        while(fast&&fast->next){
            if(fast==slow)return true;
            fast=fast->next->next;
            slow=slow->next;
            
        }
        return fast==slow;
    }
};