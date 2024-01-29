class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      int n=nums.size();
      deque<int>dq;
        //answer always in front. maintains dq in decreasing order by value
      vector<int>ans;
        for(int i=0;i<n;i++){
          //removal of smaller elements which occured before.
            while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();
           //add this el
            dq.push_back(i);
          
            //remove the outside window id,  if valid;  
            int remId= i-k;
           while(!dq.empty() && dq.front() <=remId)dq.pop_front(); 
            
            
         //add to answer   
            if(i>=k-1)ans.push_back(nums[dq.front()]);
      }
     return ans;   
    }
};