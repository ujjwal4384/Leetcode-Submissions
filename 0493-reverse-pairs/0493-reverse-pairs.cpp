class Solution {
public:
    void merge(vector<int>&nums, int l, int m, int r, int& count){
        int sz1 = m - l + 1;
        int sz2 = r - m ;
        vector<int>v1(sz1),v2(sz2);
        
        for(int i=l;i<=r;i++){
            if(i <= m)v1[i-l] = nums[i];
            else v2[i-m-1] = nums[i];
        }

        for(auto& x: v2){
            auto it = upper_bound(v1.begin(), v1.end(), 2LL*x);
            if(it == v1.end()) continue;
            int index = (it - v1.begin()); //O(1) in vectors/array (contiguous memory) 
            count += (sz1 - index);
        }
  
        int i=0,j=0,k=l;
        while(i<sz1 && j< sz2){
            if(v1[i] <= v2[j]) nums[k] = v1[i++];
            else  nums[k] = v2[j++];  
            
            k++;
        }
        while(i<sz1){
            nums[k] = v1[i++];
            k++;
        }
        while(j<sz2){
            nums[k] = v2[j++];
            k++;
        }
    }

    void mergeSort(vector<int>&nums, int l, int r, int& count){
        if(l>=r) return ;
        int m = (l+r)>>1;
        mergeSort(nums, l, m, count);
        mergeSort(nums, m+1, r, count);
        merge(nums, l, m, r, count);
    }

    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums, 0, nums.size()-1, count);
        return count;
    }
};