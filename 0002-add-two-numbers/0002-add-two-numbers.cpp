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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int n1=0,n2=0;
       ListNode* temp=l1;
       while(temp){
        n1++;
        temp=temp->next;
       }   
       temp=l2;
       while(temp){
        n2++;
        temp=temp->next;
       }

       if(n2>n1) return addTwoNumbers(l2,l1);

       ListNode* t1 = l1,*t2 =l2;
       int c = 0;
     
    

       ListNode* last_t1 = t1;
       while(t2){
            int x = t1->val, y= t2->val;
            int sum = x + y + c;
            int put = sum%10;
            c = sum/10;
            t1->val = put;
            last_t1=t1;
            t1= t1->next;
            t2 = t2->next;
       }
       while(t1){
            int x = t1->val;
            int sum = x + c;
            int put = sum%10;
            c = sum/10;
            t1->val = put;
            last_t1 = t1;
            t1= t1->next;
       }

       while(c>0){
           int sum = c;
           int put = sum%10;
           c = sum/10; 
           last_t1->next = new ListNode(put);
           last_t1 = last_t1->next;   
       }
      return l1;
    }
};