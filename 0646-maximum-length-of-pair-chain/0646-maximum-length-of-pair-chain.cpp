auto comp = [](const vector<int>&v1, const vector<int>&v2){
              return v1[1] < v2[1];  
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        
        sort(pairs.begin(), pairs.end(), comp);
        int ans = 0;
        int last_r = -1e8;
        for(auto&v: pairs){
            int l = v[0], r= v[1];
            if(l> last_r){
                ans++;
                last_r = r;
            }
        }
        return ans;
    }
};