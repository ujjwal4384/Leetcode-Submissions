class Solution {
public:

    void merge(vector<int>&nums, int l, int m, int r){
        int sz1 = m - l + 1;
        int sz2 = r - m ;
        vector<int>v1(sz1),v2(sz2);
        
        for(int i=l;i<=r;i++){
            if(i <= m)v1[i-l] = nums[i];
            else v2[i-m-1] = nums[i];
        }

  
        int i=0,j=0,k=0;
        while(i<sz1 && j< sz2){
            if(v1[i] <= v2[j]) nums[l+k] = v1[i++];
            else nums[l+k] = v2[j++];
            k++;
        }
        while(i<sz1){
            nums[l+k] = v1[i++];
            k++;
        }
        while(j<sz2){
            nums[l+k] = v2[j++];
            k++;
        }
    }

    void mergeSort(vector<int>&nums, int l, int r){
        if(l>=r) return ;
        int m = (l+r)>>1;
        mergeSort(nums, l, m);
        mergeSort(nums, m+1, r);
        merge(nums, l, m, r);
    }
    
    vector<int> sortArray(vector<int>& nums) {
         mergeSort(nums, 0, nums.size() - 1);
         return nums;
    }
};