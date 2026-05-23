class Solution {
    int getLIS(vector<int>&nums){
        int n = nums.size();
        vector<int>tail;
        for(int i=0;i<n;i++){
            auto it = lower_bound(tail.begin(), tail.end(), nums[i]);
            if(it== tail.end()){
                tail.push_back(nums[i]);
                continue;
            }
            *it = nums[i];
        }
     return tail.size();   
    }    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       int n = envelopes.size() ;
       //sort width asc, height desc, run LIS on height. to ensure LIS  only picks one of same width envelopes
       sort(envelopes.begin(), envelopes.end(), [](vector<int>&v1, vector<int>&v2){
            if(v1[0]==v2[0]) return v1[1] > v2[1];
            return v1[0] < v2[0];
       });
      
       //run LIS on height. via Binary Search
       vector<int>heights;
       for(int i=0;i<n;i++){
        heights.push_back(envelopes[i][1]);
       }
       int ans = getLIS(heights);
       return ans;
    }
};

//sort by asc height
//sort by asc width
// 2,3 -> 5,4 ->6,4 ->6,7 : make it actua asmbb\bnmakrhbd\ ahel
// whatever remains-> is our 