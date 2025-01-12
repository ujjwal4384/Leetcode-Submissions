class RangeModule {
public:
    set<pair<int,int>>s;
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto it = s.lower_bound({left, right});
        if(it != s.begin()){
            auto before = prev(it);
            if(before != s.end() && before->second>= left){
                left = min(left, before->first);
                right = max(right, before->second);
                s.erase(before);
            }
        }

        
        auto nxt = it;
        while(nxt != s.end() && right>=nxt->first){
               right = max(right, nxt->second);
               nxt++;
               s.erase(prev(nxt)); 
        }
        s.insert({left, right});
    }
    
    bool queryRange(int left, int right) {
        auto it = s.lower_bound({left, right});
        if(it!=s.end()){
            if(left >= it->first && right<=it->second) return true;
        }

        if(!s.empty()){
            it--;
            if(left >= it->first && right<=it->second) return true;
        }

        return false;
    }
    
    void removeRange(int left, int right) {
        auto it = s.lower_bound({left, right});

        auto before= it;
        if(before!=s.begin()){
            before--;
            if(left < before->second){
                int newRight = left;
                if(newRight > before->first){
                     s.insert({before->first, newRight});
                }

                if(right < before->second){
                    s.insert({right, before->second});
                }
                s.erase(before);
            }
        }

        auto nxt = it;
        int lastRight = -1;
        while(nxt !=s.end() && right >= nxt->first){
            lastRight = nxt->second;
            nxt++;
            s.erase(prev(nxt));
        }

        if(right < lastRight){
            s.insert({right, lastRight});
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */