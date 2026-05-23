class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>tail;
        //tail[i]= stores last smallest element for subsequenece of length i+1.
        //it does not store correct subsequence, just helpful for length.
        for(int i=0;i<n;i++){
                auto it = lower_bound(tail.begin(), tail.end(), nums[i]);
                if(it == tail.end()){
                    tail.push_back(nums[i]);
                    continue;
                }
                //overwrite that index with this value
                *it = nums[i];
        }

        return tail.size();
    }
};
/*

 1 7 8 4 9

 1->[1]
 7->[1, 7]
 8->[1, 7, 8]
 4 -> not greater than end of tail hence find just greater eq element and overwrite that
    -> [1, 4, 8] //Note 1 4 8 is not correct subsequence as 4 comes after 8 in array but it gives correct LIS length because we know if 8 is there there was some element smaller than 8 (7) before. not concerned on what that element was. 
5-> [1,4,8, 9] ans = 4 .tail.size()
*/