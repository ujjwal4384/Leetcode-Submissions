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
        //create nodes
        while(temp){
            oldToNewNode[temp] = new Node(temp->val);
            temp = temp->next;
           
        }
        

        //assign next & random pointer
        temp = head;
        while(temp){
            oldToNewNode[temp]->next = oldToNewNode[temp->next];
            oldToNewNode[temp]->random =  oldToNewNode[temp->random];
            temp = temp->next;
        }
        return oldToNewNode[head];
    }
};