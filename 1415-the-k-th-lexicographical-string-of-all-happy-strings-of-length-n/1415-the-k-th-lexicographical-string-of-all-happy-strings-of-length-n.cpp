class Solution {
    set<string>s;
    int N;
public:
    void solve(int i, string& str){
        if(i==N) {
            s.insert(str);
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
        s.clear();
        N =n;
        string str="";
        solve(0, str);
        if(k > s.size()) return "";
        auto it = s.begin();
        advance(it, k-1);

        return (*it);
    }
};