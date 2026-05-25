class Solution {

public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int total_sum = 0;
        for(auto & num: nums) total_sum += num;
        unordered_map<int,vector<int>>left,right;
        //left[k] =   holds all possible sum in left half with length k
        int total_combination = 1<<(n/2) ;
        for(int i=0;i<total_combination; i++){
                int sz = 0;
                int sum_left = 0, sum_right = 0;
                for(int j=0;j<n/2; j++){
                     if (i & (1 << j)){
                        sz++;
                        sum_left += nums[j];
                        sum_right += nums[j+n/2];   
                     }
                }
                left[sz].push_back(sum_left);
                right[sz].push_back(sum_right);
        }

        int mini = INT_MAX;
        //delta = total_sum - 2*S1 (S1= sum of one subset of length n/2)
        //hence S1 should be as close to total_sum/2 as possible
        //S1 = sum part of elements from left, and sum part of elements from right
        //if k is size of elements from left then we need to take n/2 -k size of element from right half. 

        for(auto&p:right){
            sort(p.second.begin(), p.second.end());
        }
        for(auto&p: left){
            int left_sz = p.first;
            vector<int>left_sums = p.second;
            vector<int>right_sums = right[n/2 -left_sz];
            if(right_sums.size()==0)continue;
            for(auto& left_sum: left_sums){
                   int target = (total_sum/2) - left_sum;
                   auto it = lower_bound(right_sums.begin(), right_sums.end(), target);
                   int right_sum ;
                   if(it == right_sums.begin()){
                        right_sum = (*it);
                   }
                   else if(it==right_sums.end()){
                        it--;
                   }
                   else if(*it != target){
                        it--;
                   }
                   right_sum = (*it);
                   int s1 = (left_sum + right_sum);
                   mini = min(mini, abs(total_sum - 2*s1));   
            }
        }
        return mini;
    }
};