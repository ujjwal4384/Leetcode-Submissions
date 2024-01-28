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
            //let's always insert in rem first
             rem.insert(newX);
            
            //balancing
            //step-1: empty the maxi multiset
            if(!maxi.empty()){
                rem.insert(*(--maxi.end()));
                maxi.erase((--maxi.end()));
            }
            //now transfer the largest element from rem to maxi.
            maxi.insert( *(--rem.end()) );
            rem.erase((--rem.end()));
            
            res.push_back(*maxi.begin());
        }
       return res; 
    }
};