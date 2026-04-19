class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size()  ;
        int i =0, j =0;
        int maxi = 0;
        while(i<n && j<m){
            if(nums2[j] >= nums1[i]){
                 maxi = max(maxi, j-i);
                 j++;
            }else{
                i++;
            }
        }
        return maxi;
    }
};