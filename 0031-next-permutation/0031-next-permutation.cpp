class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //check from last: pick first non-decreasing trend from right to left.
        // iterate: i:sz-2 ->0 stop when you find nums[i] < nums[i+1].
        //swap nums[i] with nums[j]  of j: i+1 ->sz-1. which is just greater than nums[i].
        //then reverse the i+1 ->sz-1 elements. (make them increasing order now).

        int pi = -1;
        int n = nums.size();
        for(int i=n-2;i>=0 ;i--){
            if(nums[i] < nums[i+1]){
                pi = i;
                break;
            }
        }
        if(pi == -1){
            //means nums is in descending order . hence next permutation = asc order (first one)
            reverse(nums.begin(), nums.end());
            return;
        }
        int id_to_swap = pi+1;
        for(int j=pi+1;j<n; j++){
            if(nums[j]> nums[pi]){
                  id_to_swap = j;
            }else break;
        }

        swap(nums[pi], nums[id_to_swap]);
        reverse(nums.begin() + pi+1, nums.end());
        
    }
};