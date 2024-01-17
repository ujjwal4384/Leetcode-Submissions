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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode*odd=head,*even=new ListNode(-1);
        ListNode*to=odd,*te=even;
        ListNode*to_prev;
        while(1){
         
              if(to && to->next){
                 te->next = to->next;
                 to->next=to->next->next;
                 to_prev=to;
                 to=to->next; 
                 te = te->next;
              }else if(to){
                  te->next = NULL;
                  to->next=even->next;
                  break;
              }else{
                  to_prev->next=even->next;
                  te->next = NULL;
                  break;
              }
               
        }
        
        return odd;
    }
};