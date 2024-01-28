class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     //standard problem handled by 2 multisets/priority queue.
        int n=nums.size();
        multiset<int>maxi,rem;
        for(int i=0;i<k;i++){
            rem.insert(nums[i]);
        }
        vector<int>res;
        maxi.insert((*--rem.end()));
        rem.erase((--rem.end()));
        res.push_back(*maxi.begin());
        for(int i=k;i<n;i++){
            int newX = nums[i];
            int removeX = nums[i-k];
            
            //removal
            if(maxi.find(removeX)!=maxi.end()){
                auto it = maxi.find(removeX);
                maxi.erase(it);
            }else{
                auto it = rem.find(removeX);
                rem.erase(it);
            } 
            //addition
            if(!maxi.empty() && newX> *(--maxi.end())){
                maxi.insert(newX);
            }else{
                rem.insert(newX);
            }
            //balancing
            if(maxi.size()>1){
                rem.insert(*maxi.begin());
                maxi.erase(maxi.begin());
            }else if(maxi.empty()){
                maxi.insert(*(--rem.end()));
                rem.erase(--rem.end());
            }
            res.push_back(*maxi.begin());
        }
       return res; 
    }
};