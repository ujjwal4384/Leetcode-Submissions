class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        
        // If there are only 2 stones, the only path is 0 -> 1 -> 0
        if (n == 2) return stones[1] - stones[0];
        
        int min_max_jump = 0;
        
        // The optimal path always skips exactly one stone.
        // We just find the maximum distance between alternate stones.
        for (int i = 2; i < n; i++) {
            min_max_jump = max(min_max_jump, stones[i] - stones[i-2]);
        }
        
        return min_max_jump;
    }
};