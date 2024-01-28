class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     //standard problem handled by 2 multisets/priority queue.
        int n=nums.size();
        multiset<int>rem;
        int maxi=INT_MIN;
        for(int i=0;i<k;i++){
            rem.insert(nums[i]);
        }
        vector<int>res;
        maxi= *(--rem.end());
        rem.erase((--rem.end()));
        res.push_back(maxi);
        for(int i=k;i<n;i++){
            int newX = nums[i];
            int removeX = nums[i-k];
            
            //removal
            if(removeX==maxi){
                maxi = INT_MIN;
            }else{
                auto it = rem.find(removeX);
                rem.erase(it);
            } 
            //addition
            if(maxi!=INT_MIN && newX> maxi){
                rem.insert(maxi);
                maxi = newX;
            }else{
                rem.insert(newX);
            }
            //balancing
            if(maxi==INT_MIN){
                maxi=(*(--rem.end()));
                rem.erase(--rem.end());
            }
            res.push_back(maxi);
        }
       return res; 
    }
};