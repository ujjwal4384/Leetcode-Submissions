
class Solution {
// const int INT_MAX = numeric_limits<int>::max();
// const int INT_MIN = numeric_limits<int>::min();
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(i<n && s[i] == ' ')i++;
        int multiplier = 1;
        if(i<n && s[i]=='-')multiplier = -1, i++;
        else if(i<n && s[i]=='+') i++;

        long long ans = 0;
        while(i<n){
           if('0'<=s[i] && s[i] <= '9'){
                ans = ans*10LL + (s[i] - '0');
                i++;   
           }else {break;}

           if(ans >INT_MAX)return multiplier == 1? INT_MAX : INT_MIN; 
        }
        return multiplier * ans;
    }
};