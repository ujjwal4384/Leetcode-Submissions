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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       //find difference in length of two linkedList, move the longer list dif times ahead befoe moving together.
        
        int n1=0,n2=0;
        ListNode*t1=headA,*t2=headB;
        while(t1){
            t1=t1->next;
            n1++;
        }
        while(t2){
            t2=t2->next;
            n2++;
        }
        
        if(n1<n2){
            return getIntersectionNode(headB, headA);
        }
        
        int dif = n1- n2;
        t1=headA, t2= headB;
        while(dif--){
            t1=t1->next;
        }
        while(t1!=t2){
            t1=t1->next , t2=t2->next;
        }
        
        return t1;
    }
};