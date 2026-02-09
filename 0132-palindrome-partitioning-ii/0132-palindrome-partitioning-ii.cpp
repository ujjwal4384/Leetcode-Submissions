class Solution {
    vector<int>dp;
public:
    bool isPalindrome(string&str){
        int n= str.size();
        int l=0,r=n-1;
        while(l<r){
            if(str[l]!=str[r])return false;
            l++,r--;
        }
        return true;
    }

    int f(int i, string& s){
        if(i==s.size()) return 0;
        if(dp[i] !=-1) return dp[i];
        int mini = INT_MAX;
        string cur = "";
        for(int j=i;j<s.size();j++){
                cur += s[j];
                if(isPalindrome(cur)){
                     int curCost = 1 + f(j+1, s);
                     mini = min(mini, curCost);
                }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        dp.assign(s.size(), -1);
        return f(0, s) -1;
    }
};