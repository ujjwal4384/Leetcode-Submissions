class Solution {
public:
    int f(int n){
          if(n<=1) return 1;
          int count =0;
          for(int i=1;i<=n ; i++){
            count += f(i-1)*f(n-i);
          }

          return count;  
    }
    int numTrees(int n) {
      return f(n);   
    }
};