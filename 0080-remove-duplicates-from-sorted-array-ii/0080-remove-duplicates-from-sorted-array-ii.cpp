class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n= nums.size();

        int i,j;
        for(i=0,j=0; i<n && j<n; ){
                int id=j;
                while(id+1<n&& nums[id+1]==nums[j])id++;        
                
                if(id-j==0){
                    nums[i] = nums[j];
                    i++;
                    j++;
                }
                else if(id - j >=1){
                    nums[i] = nums[j];
                    nums[i+1] = nums[j];
                    i += 2;
                    j = id+1;
                }
            
            }
        

        return min(n, i);
    }
};