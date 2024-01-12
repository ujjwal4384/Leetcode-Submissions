class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        //1 3 2 4 5 : n=5
        int n=v.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[v[i]]++;
        }
        vector<int>ans;
        for(auto&p:mp){
            if(p.second>n/3)ans.push_back(p.first);
        }
        return ans;
    }
};