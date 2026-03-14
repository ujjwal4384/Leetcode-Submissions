class Solution {
    int N, K;
    string ans = "";
public:
    void solve(int i, string& str){
        if(K<=0) return;
        if(i==N) {
            K--;
            if(K==0) {
                ans =str;
            }
            return ;
        }
        for(char ch='a';  ch<='c'; ch++){
             if(i-1>=0 && ch == str[i-1]) continue;
             str.push_back(ch);
             solve(i+1, str);
             str.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        N =n;
        K= k;
        string str="";
        solve(0, str);
        return ans;
    }
};