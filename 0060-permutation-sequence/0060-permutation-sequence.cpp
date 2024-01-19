class Solution {
public:
   int fact(int n){
        if(n<=1) return 1;
        return n * fact(n-1);
   } 
   void f(int n, int k, string&ans, set<int>&s){
       if(n==0){
           return ;
       }  
         int times = fact(n-1);
         int move = k/times ;
         int newK = k%times ; 
       
         auto it =s.begin();
         advance(it, move);
         ans+= to_string(*it);
         s.erase(it);
       
         f(n-1, newK, ans, s);
    }
    
    string getPermutation(int n, int k) {
        k--;
        set<int>s;
        for(int k=1;k<=n;k++)s.insert(k);
        string ans="";
        f(n,k,ans, s);
       return ans; 
    }
};