struct Node{
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key, int val){
         this->key = key;
         this->val = val;
         this->prev = NULL;
         this->next= NULL;
   }
};

class LRUCache {
   private:
   unordered_map<int,Node*>mp;
   int capacity; 
   Node* head;
   Node* tail;
public:
    LRUCache(int capacity) {
            this->capacity = capacity;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        //update it's location remove from here and add it on front.
        remove(node);
        mp.erase(key);
        addFront(node);
        mp[key] = node;
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            remove(node);
            mp.erase(key);
            node->val = value;
            addFront(node);
            mp[key] = node;
            return ;
        }

        if(mp.size() == capacity){
            //need to evict last recently used key
            mp.erase(tail->prev->key);
            remove(tail->prev);
        }
        //add new node in starting    
        Node* node = new Node(key, value);
        addFront(node);
        mp[key] = node;  
    }

    void addFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void remove(Node* node){
        Node* nodePrev= node->prev;
        Node* nodeNext = node->next;
        nodePrev->next = node->next;
        nodeNext->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */