struct Node{
    int key = -1;
    int val = -1;
    int freq = 1;
    Node* prev = NULL;
    Node* next = NULL;
    Node(int key, int val){
        this->key = key;
        this->val =val;
        this->freq = 1;
    }
};

struct List{
   Node* head;
   Node* tail;
   int sz;
   List(){
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
    sz = 0;
   }

   void addFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
        sz++;
    }

    void remove(Node* node){
        Node* nodePrev= node->prev;
        Node* nodeNext = node->next;
        nodePrev->next = node->next;
        nodeNext->prev = node->prev;
        node->next = NULL;
        node->prev = NULL;
        sz--;
    }
};

class LFUCache {
    private:
    unordered_map<int, Node*>mp;
    unordered_map<int, List*> freqList;
    int capacity;
    int minFreq;

    void updateFreq(Node* node){
        List* list = freqList[node->freq];
        list->remove(node);
        if(minFreq == node->freq && list->sz == 0){
                minFreq++;
        }
        node->freq++;
        int newFreq = node->freq;
        if(freqList.find(newFreq) == freqList.end()){
            freqList[newFreq] = new List();  
        }
         freqList[newFreq]->addFront(node);
    }
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        
        updateFreq(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
             Node* node = mp[key];
             node->val = value;
             updateFreq(node);
             return;
        }

        if(mp.size() == capacity){
            List* minFreqList = freqList[this->minFreq];
            Node* lru = minFreqList->tail->prev;
            minFreqList->remove(lru);
            mp.erase(lru->key);
            delete lru;
        }

        Node* node = new Node(key, value);
        minFreq = 1;
        if(freqList.find(minFreq) == freqList.end()){
            freqList[minFreq] = new List();
        }
        freqList[minFreq]->addFront(node);
        mp[key] = node;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */