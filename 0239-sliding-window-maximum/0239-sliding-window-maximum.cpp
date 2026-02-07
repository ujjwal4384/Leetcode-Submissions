class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        multiset<int>main;
        for(int i=0;i<nums.size();i++){
            main.insert(nums[i]);

            if(i>=k){
                int toRem = nums[i-k];
                    main.erase(main.find(toRem));
            }
            if(i>=k-1){
                ans.push_back( *prev( main.end() ) );
            }
        }
        return ans;
    }
};