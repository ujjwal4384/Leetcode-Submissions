class Solution {
    bool isValid(vector<int>& bloomDay, int m, int k, int days){
        int curFlowerCount = 0;
        int curBouquetCount = 0;
         for(auto x: bloomDay){
            if(x> days)curFlowerCount = 0;
            else if(x<=days){
                 curFlowerCount ++;
                 if(curFlowerCount == k)curBouquetCount ++, curFlowerCount=0;
            }
         }
         return curBouquetCount >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
         long long totalFlowersRequired = 1LL * m*k;
         int n = bloomDay.size();
         if(n < totalFlowersRequired) return -1;
         int l =1, r = *max_element(bloomDay.begin(), bloomDay.end());
         int ans = r;
         while(l<=r){
             int mid = l + ((r-l)>>1);
             if(isValid(bloomDay, m, k, mid)){
                 ans = mid;
                 r = mid -1;
             }else {
                l = mid+1;
             }
         }
         return ans;
    }
};