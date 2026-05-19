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
        unordered_map<Node*, Node*>oldToNewNode;
        Node* temp = head;
        //create and assign next pointer
        Node* newPrev = NULL;
        while(temp){
            oldToNewNode[temp] = new Node(temp->val);
            if(newPrev)
                 newPrev->next = oldToNewNode[temp];
            newPrev = oldToNewNode[temp];
            temp = temp->next;
           
        }
        

        //assign random pointer
        temp = head;
        while(temp){
            oldToNewNode[temp]->random =  oldToNewNode[temp->random];
            temp = temp->next;
        }
        return oldToNewNode[head];
    }
};