class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i =0;
        int start = 0;
        int tot_delta =0;
        int tot_diff = 0;
        while(i<gas.size()){
              int diff = gas[i] - cost[i];
              tot_diff += diff;
              if(tot_delta + diff >=0){
                  i++;
                  tot_delta += diff;
              }else{
                  tot_delta = 0;
                  start = i+1;
                  i = start;
              }
        }

        return tot_diff>=0? start : -1;
    }
};