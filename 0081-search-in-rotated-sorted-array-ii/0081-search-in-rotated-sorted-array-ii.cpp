class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //find pivot
        //2 increasing sequences. b.s
         int pi=0;
        int n= nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]){
                pi=i-1;
                break;
            }
        }
        
        return bs(0, pi, nums, target) || bs(pi+1, n-1, nums, target);
    }
    
    bool bs(int l, int r, vector<int>&v, int& target){
       if(l<=r){ 
        int m = (l+r)>>1;
        if(v[m]==target)return true;
        else if(v[m]<target){
            return bs(m+1, r, v, target);
        }else{
            return bs(l, m-1, v, target);
        }
       }
       return false;     
    }
};