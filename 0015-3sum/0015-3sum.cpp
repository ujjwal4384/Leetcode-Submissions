class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        sort(v.begin(), v.end());
        for(auto&x:v)cout<<x<<" ";cout<<endl;
        int n=v.size();
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
              int j=i+1,k=n-1;
              while(j<k){
                  int sum = v[i]+v[j]+v[k];
                  
                  if(sum==0){
                      res.push_back({v[i], v[j], v[k]});
                      while(j+1<n && v[j+1]==v[j])j++;
                      while(k-1>i && v[k-1]==v[k])k--;
                      j++,k--;
                      
                  }else if(sum<0){
                      j++;
                  }else {
                      k--;
                  }
              }
              while(i+1<n && v[i+1]==v[i])i++;
        }
        return res;
    }
};