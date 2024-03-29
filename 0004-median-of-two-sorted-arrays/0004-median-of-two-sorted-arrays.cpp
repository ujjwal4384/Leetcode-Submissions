class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();
       
     
        int n = n1 + n2;
        
        int left = (n + 1) / 2;
        
        int low1 = max(0, left-n2), high1 = min(n1, left);
        
        int l1, l2, r1, r2;
        
        while (low1 <= high1) {
            int mid1 = (low1 + high1) >> 1;
            int mid2 = left - mid1;

            l1 = mid1 - 1 >= 0 ? v1[mid1 - 1] : INT_MIN;
            l2 = mid2 - 1 >= 0 ? v2[mid2 - 1] : INT_MIN;
            r1 = mid1 < n1 ? v1[mid1] : INT_MAX;
            r2 = mid2 < n2 ? v2[mid2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1) {
                break;
            } else if (l1 > r2) {
                high1 = mid1 - 1;
            } else {
                low1 = mid1 + 1;
            }
        }

        return n % 2 ? max(l1, l2) : (max(l1, l2) + min(r1, r2)) / 2.0;
    }
    
};