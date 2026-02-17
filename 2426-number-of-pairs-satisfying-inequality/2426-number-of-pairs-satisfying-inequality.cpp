class Solution {
public:
    void merge(vector<int>&nums, int l, int m, int r, long long& count, int& diff){
        int sz1 = m - l + 1;
        int sz2 = r - m ;
        vector<int>v1(sz1),v2(sz2);
        
        for(int i=l;i<=r;i++){
            if(i <= m)v1[i-l] = nums[i];
            else v2[i-m-1] = nums[i];
        }

        for(int p=0,q=0;p<sz1&&q<sz2;){
                if(v1[p] <= v2[q]+diff){
                    count += (sz2-q);
                    p++;
                }else{
                    q++;
                }
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

    void mergeSort(vector<int>&nums, int l, int r, long long& count, int& diff){
        if(l>=r) return ;
        int m = (l+r)>>1;
        mergeSort(nums, l, m, count, diff);
        mergeSort(nums, m+1, r, count, diff);
        merge(nums, l, m, r, count, diff);
    }

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
         vector<int>v;
         for(int i=0;i<nums1.size();i++)v.push_back(nums1[i] - nums2[i]);
         long long count =0;
         mergeSort(v, 0, v.size()-1, count, diff);
         return count;
    }
};