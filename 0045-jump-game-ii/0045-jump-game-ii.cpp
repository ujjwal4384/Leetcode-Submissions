class Solution {
public:
    int jump(vector<int>& nums) {
            int n = nums.size();
            int i=0;
            int steps = 0;

            if(n<=1) return steps;

            while(i<n){
              
                if(i + nums[i] >=n-1) return steps+1;


                int next_pos = -1;
                int maxD = -1;
                
                for(int j = i; j<=i+nums[i]; j++){
                    int d = j+ nums[j];
                    if(maxD < d){
                        maxD = d, next_pos = j;
                    }
                }

               

                if(next_pos <= i){
                    if(i == n-1) return steps;
                    else return -1;
                }
                

                steps++;
                i = next_pos;
            }
        return steps;       
    }
};