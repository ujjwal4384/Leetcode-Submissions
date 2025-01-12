class Solution {
public:
   void addRange(set<pair<int,int>>&s, int left, int right){
         auto it = s.lower_bound({left, right});
         

         if(it !=s.begin() && s.size()){
            auto before = prev(it);
            
            if(left <= before->second ){
                    left = min(left, before->first);
                    right = max(right, before->second);
                     s.erase(before);
            }
         }   

         auto nxt = it;
         while(nxt!=s.end() && nxt->first <=right){
            right = max(right, nxt->second);
            nxt++;
            s.erase(prev(nxt));
         }
         s.insert({left, right});
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        set<pair<int,int>>s;
       
        for(auto&x:intervals){
             addRange(s, x[0], x[1]);
            
        }

        vector<vector<int>>res;
        for(auto& x:s){
            res.push_back({x.first, x.second});
        }

        return res;
    }
};