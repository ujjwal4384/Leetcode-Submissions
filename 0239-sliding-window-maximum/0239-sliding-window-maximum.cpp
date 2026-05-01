class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int>ans;
       deque<int>dq;
       for(int i=0;i<nums.size(); i++){
           if(i>=k && !dq.empty() && dq.back() == i-k)
               dq.pop_back();
           cout<< dq.front()<<" ";    
           while(!dq.empty() && nums[dq.front()] <= nums[i] )dq.pop_front();
           dq.push_back(i);
           if(i>=k-1)ans.push_back(nums[dq.front()]);
       }
       return ans;   
    }
};