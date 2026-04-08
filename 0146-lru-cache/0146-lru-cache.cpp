struct Node{
    int key;
    int value ;
    Node* prev ;
    Node* next ;
    Node(int key, int value){
        this->key = key, this->value = value ;
        this ->prev= NULL, this->next = NULL;
    }
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*>keyMap;
    Node * head;
    Node * tail;
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        this->capacity = capacity;
    }
    
    int get(int key) {
          // check if key present
          //if no-> then return -1

          //if yes: then update the position to front and return value  

          bool isKeyPresent = keyMap.count(key) ;
          if(!isKeyPresent) return -1;
          int value = keyMap[key]->value;
          remove(keyMap[key]);
          addFront(new Node(key, value));
          return value;
    }
    
    void put(int key, int value) {
        // check if the key exist: then delete it.
        //check current size if it is max occupancy: remove the last tail prev
        // insert new key, value pair in head next
        bool isKeyPresent = keyMap.count(key) ;
        if(isKeyPresent){
             remove(keyMap[key]);
        }
        if(keyMap.size() == capacity){
            remove(tail->prev);
        }
        addFront(new Node(key, value));
    }

    void remove(Node* nodeToRemove){
        keyMap.erase(nodeToRemove->key);
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
        delete nodeToRemove;
    }

    void addFront(Node* nodeToAdd){
           keyMap[nodeToAdd->key] = nodeToAdd;
           nodeToAdd->prev = head;
           nodeToAdd->next = head->next;
           head->next->prev = nodeToAdd; 
           head->next = nodeToAdd;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */