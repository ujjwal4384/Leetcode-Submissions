class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = 3;
        map<int,int>candidates;
        int cand1 = INT_MIN ,cand2 = INT_MIN,count1=0,count2=0;
        for(auto x:nums){
            if(cand1 == x ){
                count1++;
            }else if(cand2 == x){
                count2 ++;
            }
            else {
                if(cand1 == INT_MIN){
                    cand1 = x;
                    count1 = 1;
                }else if(cand2 == INT_MIN){
                    cand2 = x;
                    count2 = 1;
                }
                else{
                    //remove one element from each of the candidates.
                    count1 --;
                    if(count1 == 0)cand1 = INT_MIN;
                    count2 --;
                    if(count2 ==0) cand2 = INT_MIN;
                }
            }
        }

    count1 =0, count2 =0;
    for (int num : nums) {
        if(num == cand1) count1++;
        else if(num == cand2)count2++;
    }
        
    vector<int>res;
    if(count1 >n/3) res.push_back(cand1);
    if(count2 >n/3) res.push_back(cand2);
    return res;
 }
};