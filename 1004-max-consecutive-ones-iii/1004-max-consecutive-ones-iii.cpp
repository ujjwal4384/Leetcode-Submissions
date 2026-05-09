class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int left = 0, max_streak = 0, debt = 0;

        // You running down the aisle
        for (int right = 0; right < nums.size(); right++) {
            
            // You swiped your card on a premium item
            if (nums[right] == 0) debt++; 
            
            // Card declined! Accountant starts putting things back
            while (debt > k) {
                if (nums[left] == 0) {
                    debt--; // Refund!
                }
                left++; // Accountant moves forward
            }
            
            // Cart is valid, check the size
            max_streak = max(max_streak, right - left + 1);
        }
        return max_streak;
    }
};