class Solution {
public:
    void f(int pos,vector<int>& candidates,vector<vector<int>>&res, vector<int>&v, int& rem, map<int,bool>&mp){
        if(rem==0){
            res.push_back(v);
            return;
        }
        else if(rem<0 || pos==candidates.size()){
            return ;
        }
        
      
            v.push_back(candidates[pos]);
          
             rem-= candidates[pos];
        
            f(pos+1, candidates, res, v, rem, mp );
        rem+=candidates[pos];
         v.pop_back();
         int k=pos+1;
         while(k<candidates.size() && candidates[k]==candidates[pos])k++;
      
        f(k, candidates, res, v, rem, mp);
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>v;
        map<int,bool>vis;
        sort(candidates.begin(), candidates.end());
        f(0, candidates, res, v, target, vis);
        return res;
    }
};