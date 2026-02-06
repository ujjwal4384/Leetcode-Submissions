class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int K = k-1;
       
        multiset<int, greater<int>>miniSet;
        multiset<int>waitingSet;
        long long curCost = nums[0];
        long long ans = LLONG_MAX;

        for(int i=1;i<n;i++){
            //Step-1: Addition
            //always insert in minSet
            //move it to waitingSet if extra.
            miniSet.insert(nums[i]);
            curCost += nums[i];

            //Step-2: Balance
            if(miniSet.size() > K){
                waitingSet.insert(*miniSet.begin());
                curCost -= *miniSet.begin();
                miniSet.erase(miniSet.begin());          
            }

             //Step-3:Remove: Sliding Window (removal) only if i>dist+1   
            if(i>dist+1){
                int toRem = nums[i-dist-1];
                if(miniSet.find(toRem) != miniSet.end()){
                    //remove from miniSet
                    miniSet.erase(miniSet.find(toRem));
                    curCost -= toRem;
                    //need to add one from weaiting to miniSet to ensure it has K elements
                    miniSet.insert(*waitingSet.begin());
                    curCost += *waitingSet.begin();
                    waitingSet.erase(waitingSet.begin());
                }else{
                    waitingSet.erase(waitingSet.find(toRem));
                }
                
            }
            if(i>=dist+1){
                ans = min(ans, curCost);
            }
        }
      return ans;    
    }
};