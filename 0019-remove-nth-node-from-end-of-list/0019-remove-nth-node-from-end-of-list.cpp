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
    //1 2 3 4 5 6  
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp= head;
        int totalNodes = 0;
        while(temp){
            temp=temp->next;
            totalNodes++;
        }
        //from fron remove target node
        int toRemove = totalNodes - n + 1;
        temp=head;
        if(toRemove<1) 
            return NULL;
        else if(toRemove==1)
            return head->next;
        
        
        while(toRemove--){
            if(toRemove==1){
                  temp->next= temp->next->next;
                  break;
           }
            temp=temp->next;
        }
        return head;
    }
};