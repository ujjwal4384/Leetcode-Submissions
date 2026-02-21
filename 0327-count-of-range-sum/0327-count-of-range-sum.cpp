class Solution {
public:
    void merge(vector<long long>&nums, int l, int m, int r, int& lower, int& upper, int& count){
        int sz1 = m - l + 1;
        int sz2 = r - m ;
        vector<long long>v1(sz1),v2(sz2);
        
        for(int i=l;i<=r;i++){
            if(i <= m)v1[i-l] = nums[i];
            else v2[i-m-1] = nums[i];
        }

        int st=0, en=0;
        // pre[i] + lower <= pre[j]  <= pre[i] + upper
        for(int p=0;p<sz1;p++){
            long long a= v1[p]+lower;
            long long b= v1[p]+upper;
            while(st<sz2 && v2[st]<a)st++;
            en=st;
            while(en<sz2 && v2[en]<=b)en++;
            count += en-st;
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

    void mergeSort(vector<long long>&nums, int l, int r, int& lower, int& upper, int& count){
        if(l>=r) return ;
        int m = (l+r)>>1;
        mergeSort(nums, l, m, lower, upper, count);
        mergeSort(nums, m+1, r, lower, upper, count);
        merge(nums, l, m, r, lower, upper, count);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int count =0;
        vector<long long>pre(n+1, 0);
        for(int i=0;i<n;i++){
            pre[i+1] = nums[i];
            if(i>0)pre[i+1] += pre[i];
        }
        mergeSort(pre, 0, pre.size()-1, lower, upper, count);
        return count;

    }
};