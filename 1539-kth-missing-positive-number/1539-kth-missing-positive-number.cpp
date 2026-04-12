class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        //if array was empty: kth missing number =k
        //now every element we find which is <=k pushes the final answer by 1.
        int l =0, r= n-1;
        while(l<=r){
             int m = (l+r)/2 ;
             int missingCount =  arr[m] - (m+1);
             if(missingCount < k)l=m+1;
             else r=m-1;
        }
        //at end: l points to exactly that element where missing count >=k
        //hence that target sit left of l. 
        //there are total l elements left of l hence answer pushed by l units.
        return l+k;
    }
};