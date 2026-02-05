class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        int K = k-1;
       
        multiset<int, greater<int>>miniSet;
        multiset<int>waitingSet;
        long long minCost = nums[0];
        for(int i=1;i<=dist+1;i++){
                if(miniSet.size()<K){
                    minCost += nums[i];
                    miniSet.insert(nums[i]);
                }else{
                    waitingSet.insert(nums[i]);
                    int miniTop = (*miniSet.begin());
                    int waitingTop = (*waitingSet.begin());
                    if(waitingTop < miniTop){
                        miniSet.erase(miniSet.begin());
                        waitingSet.erase(waitingSet.begin());
                        miniSet.insert(waitingTop);
                        waitingSet.insert(miniTop);
                        minCost = minCost - miniTop + waitingTop;
                    }
                }
        }
        long long ans = minCost;
        //now window slides.
        int r = dist+2;
        while(r<n){
              int toAdd = nums[r], toRemove = nums[r-dist-1];
              //let's remove first.
              auto it = miniSet.find(toRemove);
              if(it != miniSet.end()){
                    miniSet.erase(it);
                    minCost -= toRemove;  
              }else{
                auto itW = waitingSet.find(toRemove);
                waitingSet.erase(itW);
              }

              //now add new guy.
              miniSet.insert(toAdd);
              minCost += toAdd;
              if(miniSet.size() > K){
                 minCost = minCost - (*miniSet.begin()) ;
                 waitingSet.insert(*miniSet.begin());
                 miniSet.erase(miniSet.begin());
              }
              int miniTop = (*miniSet.begin());
              int waitingTop = waitingSet.size()>0 ? (*waitingSet.begin()) : INT_MAX;
              if(waitingTop < miniTop){
                        miniSet.erase(miniSet.begin());
                        waitingSet.erase(waitingSet.begin());
                        miniSet.insert(waitingTop);
                        waitingSet.insert(miniTop);
                        minCost = minCost - miniTop + waitingTop;
              }
              r++;
              ans = min(ans, minCost);
        }

     return ans;   
    }
};