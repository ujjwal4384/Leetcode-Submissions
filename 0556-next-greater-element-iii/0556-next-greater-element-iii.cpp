class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>nums;
        //123
        while(n){
            nums.push_back(n%10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());
         int pi = -1;
        int sz = nums.size();
        for(int i=sz-2;i>=0 ;i--){
            if(nums[i] < nums[i+1]){
                pi = i;
                break;
            }
        }
        if(pi == -1){
            return -1;
        }
        int id_to_swap = pi+1;
        for(int j=pi+1;j<sz; j++){
            if(nums[j]> nums[pi]){
                  id_to_swap = j;
            }else break;
        }

        swap(nums[pi], nums[id_to_swap]);
        reverse(nums.begin() + pi+1, nums.end());
        long long ans = 0;
        for(auto& num: nums){
            ans = ans*10 + num;
        }
        return ans > INT_MAX ? -1 : ans;
    }
};