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
          bool isKeyPresent = keyMap.count(key) ;
          if(!isKeyPresent) return -1;
          Node* node = keyMap[key];
          remove(node);
          addFront(node);
          return node->value;
    }
    
    void put(int key, int value) {
     
        auto it = keyMap.find(key) ;
        if(it != keyMap.end()){
             remove(it->second);
             it->second->value = value;
             addFront(it->second);
             return;
        }
        if(keyMap.size() == capacity){
            Node* lruNode = tail->prev;
            remove(lruNode);
            keyMap.erase(lruNode->key);
            delete lruNode;
        }
        Node* node = new Node(key, value);
        addFront(node);
        keyMap[key] = node;
    }

    void remove(Node* nodeToRemove){
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
    }

    void addFront(Node* nodeToAdd){
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