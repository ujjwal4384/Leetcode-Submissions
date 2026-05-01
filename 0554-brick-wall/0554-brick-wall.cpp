/*THOUGHT PROCESS
        line has to pass from one of the gaps of one of the rows.
        iteratoe thorugh all rows: all the gaps: try making a line there.
        now for every other row: check by prefixSum. if distance from left edge fo wall to certain index has exact same prefix sum as was till gap line. then no brick crossed. else yes brick is crossed.
          Time: O(n_rows * n_gaps * n_rows)


          Now to optimse: 
          it verticle line has to pass through one of the gaps. keep count of all the unique gaplength in map<>. pick the one with max freq. => those many rows donot cu the brick. 
       */   
#define ll long long
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
       int n_rows = wall.size();
       unordered_map<ll,int>gap_length_count;
       for(auto& row:wall){
        ll pre = 0;
        for(int i=0;i<row.size() -1; i++){
             pre += row[i];
             gap_length_count[pre] ++;
        }
       }

       int max_freq = 0;
       for(auto& p : gap_length_count){
         max_freq = max(max_freq, p.second);
       }
       int max_no_brick_cross_rows = max_freq;
       return n_rows - max_no_brick_cross_rows;
    }
};