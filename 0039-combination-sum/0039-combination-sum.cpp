class Solution {
public:
    void f(vector<int>& candidates, int pos, int rem, vector<vector<int>>&res, vector<int>&v){
        if(rem==0){
            res.push_back(v);
            return;
        }
        else if(rem<0){
            return;
        }
        if(pos==candidates.size()){
            return;
        }
        
        v.push_back(candidates[pos]);
            f(candidates, pos, rem-candidates[pos], res, v);
        v.pop_back();
            f(candidates, pos+1, rem, res, v);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>res;
        vector<int>v;
        f(candidates, 0, target, res, v);
            return res;
    }
};