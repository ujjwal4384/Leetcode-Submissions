class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        //it is equivalent of mini of S2-S1. 
        int N=nums.size();//N= even
        //calculate left and right subsets
        int sum=0;
        for(auto x: nums)sum+=x;
        vector<int>left(N/2 + 1),right(N-N/2 + 1);
        //subsets generations

        for(int i=0;i<(1<<N/2); i++){
            int sz=0;
            int l=0,r=0;
            for(int j=0;j<N/2;j++){
                if( i& (1<<j) ){
                  
                    l+=nums[j];
                }
               
            }
             left.push_back(l);
        }
        
        for(int i=0;i<(1<<(N-N/2)); i++){
            int sz=0;
            int l=0,r=0;
            for(int j=0;j<(N-N/2);j++){
                if( i& (1<<j) ){
                   
                    r+=nums[j+N/2];
                }
            }
             
             right.push_back(r);
        }
        sort(right.begin(),right.end());
        int maxPart1Sum=INT_MIN;
        for(auto x: left){
                int target = sum/2 - x;
                auto it = lower_bound(right.begin(), right.end(), target);
                if(it==right.end() || (*it) != target ){
                    it--;
                }
                if(it== (--right.begin()) ){
                    continue;
                }
                maxPart1Sum = max(maxPart1Sum, (*it) + x);
        
        }
       return abs(sum - 2*maxPart1Sum); 
    }
};