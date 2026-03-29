class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, ' '); // Initialize an empty string of length n
        char currentChar = 'a';
        
        // Phase 1 & 2: Greedily Group and Construct the Skeleton
        for (int i = 0; i < n; i++) {
            // If this index hasn't been assigned a character yet
            if (s[i] == ' ') {
                // If we need a 27th character, it's impossible
                if (currentChar > 'z') return ""; 
                
                // Assign this character to index i, and EVERY index j that shares a prefix
                for (int j = i; j < n; j++) {
                    if (lcp[i][j] > 0) {
                        s[j] = currentChar;
                    }
                }
                currentChar++; // Move to the next letter for the next unique group
            }
        }
        
        // Phase 3: The "Construct and Verify" Audit
        // We build a brand new LCP matrix using ONLY our generated string 's'
        vector<vector<int>> actualLCP(n, vector<int>(n, 0));
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                // The exact forward DP Engine we built earlier
                if (s[i] == s[j]) {
                    actualLCP[i][j] = 1 + ((i + 1 < n && j + 1 < n) ? actualLCP[i+1][j+1] : 0);
                } else {
                    actualLCP[i][j] = 0;
                }
                
                // THE TRAP DOOR: If our generated matrix differs from the input matrix
                // in even a single cell, the input matrix was mathematically impossible.
                if (actualLCP[i][j] != lcp[i][j]) {
                    return "";
                }
            }
        }
        
        return s;
    }
};