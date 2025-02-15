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
    ListNode* merge2List(ListNode* &l1, ListNode* &l2){
             if(!l1)return l2;
             else if(!l2) return l1;
             else if(l1->val <= l2->val){
                l1->next = merge2List(l1->next, l2);
                return l1;
             }
             else{
                l2->next = merge2List(l1, l2->next);
                return l2;
             }
            return NULL; 
    }

    ListNode* mergeLists(vector<ListNode*>& lists, int start, int end){
        if(start > end) return NULL;
        if(start == end) return lists[start];                       
         else if(start +1 == end) return merge2List(lists[start], lists[end]);

         int mid = (start + end)/2;

         ListNode* l1 = mergeLists(lists, start, mid);
         ListNode* l2 = mergeLists(lists, mid+1, end);

         return merge2List(l1, l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
           
        return mergeLists(lists, 0, lists.size()-1);     
    }
};