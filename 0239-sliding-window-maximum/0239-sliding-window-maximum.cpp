class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        multiset<int>main;
        multiset<int, greater<int>>reserve;
        for(int i=0;i<nums.size();i++){
            main.insert(nums[i]);
            if(main.size() > 1){
                reserve.insert(*main.begin());
                main.erase(main.begin());  
            }

            if(i>=k){
                int toRem = nums[i-k];
                if(main.find(toRem) != main.end()){
                    main.erase(main.find(toRem));
                    main.insert(*reserve.begin());
                    reserve.erase(reserve.begin());
                }else{
                    reserve.erase(reserve.find(toRem));
                }
            }
            if(i>=k-1){
                ans.push_back( *prev( main.end() ) );
            }
        }
        return ans;
    }
};