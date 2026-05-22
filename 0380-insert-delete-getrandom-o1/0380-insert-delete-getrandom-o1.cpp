class RandomizedSet {
    unordered_map<int,int>mp;
    vector<int>v;
public:
    RandomizedSet() {
        srand(time(nullptr));
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false;
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int index = mp[val];
        int lastElement = v.back();
        swap(v[index], lastElement);
        mp[v[index]] = index;
        v.pop_back();
        mp.erase(lastElement);
        return true;
    }
    
    int getRandom() {
         int sz = v.size();
         int id = rand()%sz;
         return v[id];        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */