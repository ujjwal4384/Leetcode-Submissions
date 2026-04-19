class Solution {
public:
vector<int> kmp(vector<int>&pat){
        
         int n = pat.size();
         vector<int>lps(n, 0);
         int i = 1, len = 0;
         while(i<n){
             if(pat[i] == pat[len]){
                len ++;
                lps[i] = len;
                i++;
             }else{
                   if(len!=0)len = lps[len-1];
                   else i++;
             }
         }
         return lps;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        vector<int>encode;
        for(int i=0;i<n-1;i++){
             int x ;
             if(nums[i] < nums[i+1]) x = 1;
             else if(nums[i] > nums[i+1]) x = -1;
             else x = 0;
             encode.push_back(x);
        }
         vector<int>lps = kmp(pattern);
        int i=0, j=0;
        int count = 0;
        while(i< encode.size()){
                if(encode[i] == pattern[j]){
                     i++, j++;
                     if(j==m){
                        count++;
                        j = lps[j-1] ;
                     }
                }else{
                    if(j!=0) j = lps[j-1];
                    else i++;
                }
        }
        return count;
    }
};