class Solution {
    
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
      int n = nums1.size();
      vector<pair<int,int>>vp(n);
      for(int i=0 ; i<n; i++){
        vp[i] = {nums1[i], nums2[i]};
      }  
      //SORT by min element of nums2 desc
      sort(vp.begin(), vp.end(), [](const pair<int,int>&p1,const pair<int,int>&p2){
         return p1.second > p2.second;
      });
      
      long long ans = 0;
      long long sum = 0;
      priority_queue<int, vector<int>, greater<int>>pq;
      for(int i=0;i<n;i++){
         auto p = vp[i];
         int mini = p.second;
         if(pq.size() == k-1){
            ans = max(ans, (sum + p.first)*mini);
         }
         sum += p.first;
         pq.push(p.first);
         if(pq.size()>k-1){
            sum -= pq.top();
            pq.pop();
         }
      }
      return ans;
    }
};