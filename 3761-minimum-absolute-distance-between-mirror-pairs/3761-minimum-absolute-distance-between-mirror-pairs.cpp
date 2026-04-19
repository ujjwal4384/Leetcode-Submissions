class Solution {
private:
    int reverseNum(int n) {
        int rev = 0;
        while (n > 0) {
            rev = rev * 10 + (n % 10);
            n /= 10;
        }
        return rev;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        
        for (int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }
        
        // Sorts by value, then by index ascending
        sort(v.begin(), v.end());
        
        int min_dist = INT_MAX;
        
        // Iterate i and search forward for j
        for (int i = 0; i < n; i++) {
            int target = reverseNum(nums[i]);
            
            // Search for the target value starting exactly one index to the right
            auto it = lower_bound(v.begin(), v.end(), make_pair(target, i + 1));
            
            // If we found the target, the iterator inherently holds the smallest valid j
            if (it != v.end() && it->first == target) {
                min_dist = min(min_dist, it->second - i);
            }
        }
        
        return min_dist == INT_MAX ? -1 : min_dist;
    }
};