struct Node{
 int key;
 int val; 
 int freq;
 Node* prev;
 Node* next;
 Node(int key, int val){
        this->key = key;
        this->val = val;
        this->freq = 1;
        this->prev = NULL;
        this->next = NULL;
 }
};

struct List{
  Node* head;
  Node* tail;
  int sz;
  List(){
         sz = 0;
         head = new Node(-1, -1);
         tail = new Node(-1, -1);
         head->next = tail;
         tail->prev = head;
  }

  void addFront(Node* node){
       node->prev = head;
       node->next = head->next;
       head->next->prev = node;
       head->next = node;
       sz++;
  }
  void removeNode(Node * node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        sz--;
  }
};

class LFUCache {
    unordered_map<int, Node*>keyNodeMap;
    unordered_map<int, List*>freqListMap;
    int maxSize;
    int minFreq = 0;

    void updateFreq(Node* node){
        int freq = node->freq;
        List* list = freqListMap[node->freq];
        //remove node from this freq list and add on freq+1
        list->removeNode(node);

        if(freq == minFreq && list->sz == 0){
            minFreq ++;
        }
        node->freq++;
        if(freqListMap.find(node->freq) == freqListMap.end()){
            freqListMap[node->freq] = new List();
        }
        freqListMap[node->freq]->addFront(node);
    }
public:
    LFUCache(int capacity) {
        maxSize = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyNodeMap.find(key) == keyNodeMap.end()) {
              return -1;   
        }
        Node * node = keyNodeMap[key];
        updateFreq(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (maxSize == 0) return;
        auto it = keyNodeMap.find(key);
        if(it != keyNodeMap.end()){
             it->second->val = value;
             updateFreq(it->second);
             return ;
        }

        if(keyNodeMap.size() == maxSize){
             //remove LRU
             List* minList = freqListMap[minFreq];
             Node* lruNode = minList->tail->prev;
             keyNodeMap.erase(lruNode->key);
             minList->removeNode(lruNode);
             delete lruNode;
        }
        Node* newNode = new Node(key, value);
        keyNodeMap[key] = newNode;
        minFreq = 1;
        if(freqListMap.find(minFreq) == freqListMap.end()){
            freqListMap[minFreq] = new List();
        }
        freqListMap[minFreq]->addFront(newNode);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */