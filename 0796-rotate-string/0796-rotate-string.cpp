class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();
        if(n != m) return false;
        goal += goal;
        for(int i=0;i<n;i++){
            int matchLength = 0;
            int j = i, k=0;
            while(j<2*n && k< n && goal[j] == s[k])matchLength++, j++,k++;
            if(matchLength == n) return true;
        }
      return false;
    }
};