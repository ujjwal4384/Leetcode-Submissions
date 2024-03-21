class Solution {
public:
    bool isPalindrome(int x) {
       string str= to_string(x);
       int i=0,j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j])return false;
            i++,j--;
        }
       return true; 
    }
};