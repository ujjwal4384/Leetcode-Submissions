class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int total_gas =0;
        int total_cost = 0;
        int i=0;
        int start = 0;
        int cur_gas_left = 0;
        while(i<n){
             total_gas += gas[i];
             total_cost += cost[i];
             int diff = gas[i] - cost[i];
             if(diff + cur_gas_left >=0){
                 cur_gas_left += diff;
                 i++;
             }else{
                start = i+1;
                i++;
                cur_gas_left = 0;
             }
        }
      return total_gas < total_cost ? -1 : start;
    }
};