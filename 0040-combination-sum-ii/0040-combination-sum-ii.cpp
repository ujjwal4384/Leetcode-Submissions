class Solution {
public:
void func(int i, vector<int>&v,vector<vector<int>>&vv,vector<int>& arr, int& target, int sum){
        if(sum>target) return;
        else if(sum == target){
            vv.push_back(v);
            return;
        } else if(i>=arr.size()){
            return;
        }

        //include
        v.push_back(arr[i]);
        func(i+1,v, vv, arr, target, sum+arr[i]);
        v.pop_back();

        //exclude
        int j = i+1;
        while(j<arr.size() && arr[j] == arr[i])j++;
        func(j,v, vv, arr, target, sum);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       sort(candidates.begin(), candidates.end());
       vector<vector<int>>vv;
       vector<int>v;
       int sum =0;
       func(0, v, vv, candidates, target, sum);
       return vv;    
    }
};
// 1 2 2 2 5 