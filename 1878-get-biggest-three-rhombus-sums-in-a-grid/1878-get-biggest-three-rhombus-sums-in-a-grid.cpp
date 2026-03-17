class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<int> distinct_sums; // Automatically sorts ascending and keeps unique

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                // 1. Size 0 Rhombus (Single Cell)
                distinct_sums.insert(grid[i][j]);

                // 2. Expand outwards with radius L
                for (int L = 1; ; L++) {
                    // Check if the bottom, left, and right bounds are valid
                    if (i + 2 * L >= m || j - L < 0 || j + L >= n) {
                        break; 
                    }

                    int sum = 0;
                    int r = i, c = j;

                    // Walk Top -> Right
                    for (int k = 0; k < L; k++) sum += grid[r++][c++];
                    // Walk Right -> Bottom
                    for (int k = 0; k < L; k++) sum += grid[r++][c--];
                    // Walk Bottom -> Left
                    for (int k = 0; k < L; k++) sum += grid[r--][c--];
                    // Walk Left -> Top
                    for (int k = 0; k < L; k++) sum += grid[r--][c++];

                    distinct_sums.insert(sum);
                }
            }
        }

        // Extract the top 3 (or fewer) distinct sums
        vector<int> ans;
        for (auto it = distinct_sums.rbegin(); it != distinct_sums.rend(); ++it) {
            ans.push_back(*it);
            if (ans.size() == 3) break;
        }

        return ans;
    }
};