class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //if current reach is 1->reach
        //next number is x.
        // if x <= 1+reach . then new reach becomes: reach+x. (you can add x from all number made from 1 to reach).
        //but if x> 1+reach. it means you can make all numbers from 2+reach to x+reach, but not 1+reach. example: 1,2,4 : cur reach is 7. now say next number x = 10 , we cannot make 8,9 from it. in this case we need to patch optimal number = (1+reach)  which can make next number also and increase the reach till 2*reach+1 . (0 overlapping).

        int patches = 0;
        long long reach = 0;
        int i = 0;
        while(reach < n){
             if(i<nums.size() && nums[i] <= reach+1){
                    reach = reach + nums[i];
                    i++;
             }else{
                  patches++; //add reach+1 number
                  reach = reach + (reach + 1);
             }
        }

        
        return patches;
    }
};