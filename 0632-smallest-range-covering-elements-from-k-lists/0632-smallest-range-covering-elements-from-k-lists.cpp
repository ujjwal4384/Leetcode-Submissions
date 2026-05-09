using ppi = pair<int,pair<int,int>> ;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //{val ,{row,col}}
        multiset< ppi >ms;
        int m = nums.size(), n = nums[0].size();
        for(int i=0;i<m;i++){
            ms.insert({nums[i][0], {i,0}});
        }
        set<ppi>s;
        while(ms.size() == m){
                auto it1 =  ms.begin();
                auto it2 =  --ms.end();
                
                auto [mini, cord1] = *it1;
                auto [maxi, cord2] = *it2;
                auto [i1,j1] = cord1;
                auto [i2,j2] = cord2;
                s.insert({maxi-mini,{mini, maxi}});

                ms.erase(it1);
                if(j1< nums[i1].size() -1 ){
                     
                    ms.insert({ nums[i1][j1+1] ,{i1, j1+1}});
                }

        }
        auto it = s.begin();
        return {it->second.first, it->second.second};
    }
};