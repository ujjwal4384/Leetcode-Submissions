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
       ListNode* dummyHead = new ListNode(-1);       
       int k = lists.size();
       
       ListNode* tmp = dummyHead;
       priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
       
       for(int i=0;i<k;i++){
           if(lists[i] != NULL){
                int index = i;
                int value = lists[i]->val;
                pq.push({value, index});
           }
            
       }//k*log(k)
        
       //n*k*log(n*k)
       while(!pq.empty()){
           auto it = pq.top();
           pq.pop();
           
           int value = it.first;
           int index = it.second;
           
           tmp->next = lists[index];
           tmp = tmp->next;
           lists[index] = lists[index]->next;
            
          if(lists[index]){
             pq.push( { lists[index]->val, index} ) ;
          }
       }

       return dummyHead->next;
    }
};