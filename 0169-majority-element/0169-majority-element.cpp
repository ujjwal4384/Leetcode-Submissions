class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
       
        //if moore alogrithm returns x it means x will be for sure the majority element, if ther is any. 
//so, we need to check for the returned x if he is majority.
        int potential_majority= moore_algo(nums);
       
        int freq=0;
        for(auto&num:nums)freq += (num==potential_majority);
        
        return freq>n/2 ? potential_majority : -1;
    }
    
    int moore_algo(vector<int>&nums){
        int n =nums.size();
        int candidate;
        int count=0;
        //count 0=>so far no such array section selected. start fresh again to find majority el
        for(int i=0;i<n;i++){
            if(count==0){
                candidate=nums[i];
                count=1;
            }
            else if(nums[i]==candidate)count++;
            else count--;
            
        }
        return candidate;
    }
};