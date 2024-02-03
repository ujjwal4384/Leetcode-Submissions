struct keyVal{
  int key;
  int val;   
  keyVal(int key, int val){
      this->key=key;
      this->val=val;
  }
};
class LRUCache {
    list<keyVal>ls;
    map<int, list<keyVal>::iterator>mp;
    int csize;
public:
        
    LRUCache(int capacity) {
            csize = capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
           return -1;
        }
        auto it = mp.find(key);
       
        keyVal kv = keyVal(*(it->second));
        ls.erase(it->second);
        ls.push_front(kv);
        mp[key] = ls.begin();
      return ls.begin()->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(ls.size()<csize){
                ls.push_front(keyVal(key, value));
                mp[key] = ls.begin();
            }else{
                auto it = (--ls.end());
                mp.erase(it->key);
                ls.pop_back();
                ls.push_front(keyVal(key, value));
                mp[key] = ls.begin();    
            }
        }else{
            auto it = mp.find(key);
            ls.erase(it->second);
          
            ls.push_front(keyVal(key, value));
            mp[key] = ls.begin();
        }
        return ;
    }
};

// (MRU)1->2->4->5->6 (LRU): get(4): 4->1->2->5->6
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */