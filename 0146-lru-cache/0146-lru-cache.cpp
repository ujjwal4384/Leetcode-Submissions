struct MyListNode{
    int key;
    int val;
    MyListNode* prev;
    MyListNode* next;
    MyListNode(int key, int val){
         this->key =key;
         this->val = val;
    }
};

class LRUCache {
   map<int, MyListNode*>mp;
   int capacity ;
   MyListNode* head;
   MyListNode* tail;
public:
    LRUCache(int capacity) {
        this->capacity =capacity;
        head = new MyListNode(-1, -1);
        tail = new MyListNode(-1, -1);   
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        MyListNode* node = mp[key]; 
        int val = node->val;
        deleteNode(node);
        addFront(node);  
        return val;
    }
    
    void put(int key, int val) {
        MyListNode* newNode = new MyListNode(key, val);
        if(mp.find(key) != mp.end()){
             MyListNode* node = mp[key];
             deleteNode(node);
             addFront(newNode);
             mp[key] = newNode;
             return ;
        }
        
        if(mp.size() == capacity){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addFront(newNode);
        mp[key] = newNode;
    }

    void addFront(MyListNode* node){
         MyListNode* headNext = head->next;
         head->next = node;
         node->prev = head;
         node->next = headNext;
         headNext->prev = node;
    }

    void deleteNode(MyListNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
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