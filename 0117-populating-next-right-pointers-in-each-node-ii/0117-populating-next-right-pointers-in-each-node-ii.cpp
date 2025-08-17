/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
      Node* curNode = root;
      while(curNode){
           Node* dummyHead = new Node(-1000);
           Node* nextLevelHead = dummyHead;
           while(curNode){
            if(curNode->left){
                nextLevelHead->next = curNode->left;
                nextLevelHead = nextLevelHead->next;
            }
            if(curNode->right){
                nextLevelHead->next = curNode->right;
                nextLevelHead = nextLevelHead->next;
            }
            curNode = curNode->next;
        }
        curNode = dummyHead->next; 
      }  
      return root;        
    }

    
};