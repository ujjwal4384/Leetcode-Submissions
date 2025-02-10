class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int ans = n+1;

        int s =0;
        for(int st=0, en=0; en<n; en++){
            s += nums[en];
            
            if(s>=target){
                while(st<=en){
                    if(s - nums[st] >= target){
                        s -= nums[st];
                        st++;
                    }
                    else break;
                }
               
                ans = min(ans, en-st+1);
               
                
                s -= nums[st];
                st++;
            }
        }

        return ans == n+1 ? 0 : ans;
    }
};