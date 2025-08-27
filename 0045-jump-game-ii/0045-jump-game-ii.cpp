class Solution {
public:
    int jump(vector<int>& nums) {
         int n = nums.size();
         int i =0;
    
        if(n<=1) return 0;
        int jump = 1;
        while(i<n && jump <=n){
            int max_jump = 0;
            
            int id = -1;
            
            if(i + nums[i] >= n-1) return jump;

            for(int pos = i;pos<=min(n-1, i+nums[i]); pos++){
                 if(pos + nums[pos] > max_jump){
                    max_jump = pos + nums[pos];
                    id = pos;
                 }
            }
            if(id == -1) return -1;
            
            i = id == i ? i + nums[i] : id;
            
            if(i >= n-1){
                return jump;
            }
            
            jump++;
        }

        return false;
    }
};