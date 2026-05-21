class MyHashMap {
private: 
  // request (key, value) -> hash(key) -> h1 -> bucket h1. 
  //in case of collisions-> every bucket has chaining (linkedlist)
  vector<list<pair<int,int>>>map;
  int sz;

  int hash(int key){
      return key%sz;
  }
public:
    MyHashMap() {
        sz = 2069;
        map.resize(2069);
    }
    
    void put(int key, int value) {
        int bucketNumber = hash(key);

        //if key already exist then just update value
        for(auto& node: map[bucketNumber]){
            if(node.first == key){
                node.second = value;
                return;
            }
        }

        map[bucketNumber].push_back({key, value});

    }
    
    int get(int key) {
            int bucketNumber = hash(key);
            for(auto& node: map[bucketNumber]){
            if(node.first == key){
                return node.second;
                
            }
        }
      return -1;
    }
    
    void remove(int key) {
            int bucketNumber = hash(key);
            for(auto it=map[bucketNumber].begin(); it != map[bucketNumber].end(); it++){
                if(it->first == key){
                    map[bucketNumber].erase(it);
                    return;
                }
            }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */