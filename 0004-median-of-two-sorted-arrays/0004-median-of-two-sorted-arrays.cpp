class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int i=0,j=0,k=0;
        vector<int>v1(n1+n2);
        while(i<n1 && j<n2){
            if(nums1[i]<=nums2[j])v1[k++]=nums1[i++];
            else v1[k++]=nums2[j++];
        }
        while(i<n1){
            v1[k++]=nums1[i++];
        }
        while(j<n2){
            v1[k++]=nums2[j++];
        }
        
        //if n=odd one element->v[n/2], else, (v[n/2-1]+v[n/2])/2
        
        return n%2? (double)v1[n/2] : (v1[n/2 -1]+v1[n/2])/2.0;
    }
};