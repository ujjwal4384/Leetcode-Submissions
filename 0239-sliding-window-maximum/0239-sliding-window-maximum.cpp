class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>ans;
        deque<int>dq;
        //make sure front element is always maximum.
        //when new guy comes and it is greater than back elements, keep poping the back elements because they can never be maximum going ahead.
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front() == i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[i] >= nums[ dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }

      return ans;
    }
};