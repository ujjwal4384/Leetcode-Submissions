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
        if(!head) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) return true;
        }            

        return false;
    }
    ListNode *detectCycle(ListNode *head) {
       if(!head || !head->next) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        
    
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                break;  
            }
        }            

        if(!fast || !fast->next) return NULL;
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};