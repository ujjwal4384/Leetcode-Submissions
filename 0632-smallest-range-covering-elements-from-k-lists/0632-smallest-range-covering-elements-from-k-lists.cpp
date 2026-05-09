using ppi = pair<int,pair<int,int>> ;
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //{val ,{row,col}}
        set< ppi >s;
        int m = nums.size(), n = nums[0].size();
        for(int i=0;i<m;i++){
            s.insert({nums[i][0], {i,0}});
        }
        int ans_mini = 0, ans_maxi = INT_MAX; 
        while(s.size() == m){
                auto it1 =  s.begin();
                auto it2 =  --s.end();
                
                auto [mini, cord1] = *it1;
                auto [maxi, cord2] = *it2;
                auto [i1,j1] = cord1;
                auto [i2,j2] = cord2;
                if(( ans_maxi - ans_mini ==  maxi - mini  && mini < ans_mini) || ( ans_maxi - ans_mini >  maxi - mini)){
                    ans_mini = mini;
                    ans_maxi = maxi;
                }

                s.erase(it1);
                if(j1< nums[i1].size() -1 ){
                     
                    s.insert({ nums[i1][j1+1] ,{i1, j1+1}});
                }

        }
       
        return {ans_mini, ans_maxi};
    }
};