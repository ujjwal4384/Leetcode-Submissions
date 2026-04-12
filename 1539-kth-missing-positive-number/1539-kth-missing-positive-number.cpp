class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        //if array was empty: kth missing number =k
        //now every element we find which is <=k pushes the final answer by 1.
        for(int i=0 ;i<n;i++){
            if(arr[i]<=k)k++;
            else break;
        }
        return k;
    }
};