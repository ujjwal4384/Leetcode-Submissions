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

      
        // step-1: interweave. add new node in middle of two old nodes.
       while(temp){
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
       } 

       // step-2: assign random pointer for new nodes
       temp = head; 
       while(temp){
             temp->next->random = temp->random ? temp->random->next: NULL;
             temp = temp->next->next;   
       } 
       
      //step-3: separate new node list from old.  
      Node* newHead = head->next;
      temp = head;
      while(temp){
            Node* curOldNode = temp;
            Node* nextOldNode = temp->next->next;

            Node* curNewNode = temp->next;
            Node* nextNewNode = nextOldNode ? nextOldNode->next : NULL;

            curOldNode->next = nextOldNode;
            curNewNode->next = nextNewNode;

            temp = nextOldNode;
      }
       
      return newHead;
    }
};