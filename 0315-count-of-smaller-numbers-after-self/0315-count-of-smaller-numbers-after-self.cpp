class Solution {
public:
    void merge(vector<pair<int,int>>&v, int l, int m, int r, vector<int>&count){
        int sz1 = m - l + 1;
        int sz2 = r - m ;
        vector<pair<int,int>>v1(sz1),v2(sz2);
        
        for(int i=l;i<=r;i++){
            if(i <= m)v1[i-l] = v[i];
            else v2[i-m-1] = v[i];
        }

        //counting
        for(int p=sz1-1,q=sz2-1; p>=0 && q>=0;){
            if(v1[p].first <= v2[q].first) q--;
            else{
                count[v1[p].second] += (q+1);
                p--;
            }
        }
  
        int i=0,j=0,k=l;
        while(i<sz1 && j< sz2){
            if(v1[i].first <= v2[j].first){
                 v[k] = v1[i++];
            }
            else{
                  v[k] = v2[j++];  
            }
            k++;
        }
        while(i<sz1){
            v[k] = v1[i++];
            k++;
        }
        while(j<sz2){
            v[k] = v2[j++];
            k++;
        }
    }

    void mergeSort(vector<pair<int,int>>&v, int l, int r, vector<int>&count){
        if(l>=r) return ;
        int m = (l+r)>>1;
        mergeSort(v, l, m, count);
        mergeSort(v, m+1, r, count);
        merge(v, l, m, r, count);
    }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int>count(nums.size(),0);
        vector<pair<int,int>>v; //{nums[i], i}
        for(int i=0;i<nums.size(); i++){
            v.push_back({nums[i], i});
        }
         mergeSort(v, 0, v.size()-1, count);
         return count;
    }
};