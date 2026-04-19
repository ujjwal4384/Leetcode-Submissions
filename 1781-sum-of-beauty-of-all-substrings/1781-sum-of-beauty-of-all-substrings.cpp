class Solution {
public:
    int beautySum(string s) {
          int n = s.size()  ;
          int ans = 0;
          for(int i=0;i<n;i++){
            vector<int>bucket(n+1, 0);
            vector<int>freq(26, 0);
            for(int j=i; j<n ;j++){
                       int curFreq = freq[s[j]-'a'];
                       freq[s[j]-'a']++;
                        if(curFreq>0){
                            bucket[curFreq]--;
                        }
                        bucket[freq[s[j]-'a']]++; 
                        int minFreq = -1, maxFreq = -1;
                        for(int p=0;p<n+1; p++){
                            if(bucket[p] > 0){
                                if(minFreq==-1)minFreq = p;
                                else 
                                   maxFreq = p; 
                            }
                        }
                        if(minFreq != -1 && maxFreq != -1)
                           ans += (maxFreq - minFreq);
            }
          }
      return ans;    
    }
};