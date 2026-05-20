/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* temp = head;
        //create clone nodes and interweave
        while(temp){
            
            Node* clone = new Node(temp->val);
            clone->next = temp->next;
            temp->next = clone;
            temp = clone->next;
        }
        
        //assign random pointer
        temp = head;
        while(temp){
             Node* clone = temp->next;
             clone->random = temp->random ? temp->random->next : NULL;
             temp = clone->next;
        }

        //assign next pointer and break the interweaving
        temp = head;
        Node* cloneHead = temp->next;
        while(temp){
            Node* clone = temp->next;
            temp->next = clone->next;
            clone->next = temp->next ? temp->next->next : NULL;
            temp = temp->next;
        }
        return cloneHead;
    }
};