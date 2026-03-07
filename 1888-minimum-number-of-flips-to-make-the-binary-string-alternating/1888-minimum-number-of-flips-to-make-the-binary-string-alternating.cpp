class Solution {
public:
    int minFlips(string s) {
        int n= s.size();
        if(n<=1) return 0;
        string tar1="",tar2="";
        for(int i=0;i<n;i++){
            tar1 += "10";
            tar2 += "01";
        }

        string t = s + s;
        int ans = n;
        int dif1 =0, dif2 =0;
        for(int i=0; i<2*n ; i++){
            //process new element-> increase dif if mismatch from global targets
            if(t[i] != tar1[i] )dif1++;
            if(t[i] != tar2[i] )dif2++;

            //process to remove element-> reduce dif if mismatch from global targets
            if(i>=n){
                if(t[i-n] != tar1[i-n])dif1--;
                if(t[i-n] != tar2[i-n])dif2--;
            }
            if(i>=n-1){
                ans = min({ans, dif1, dif2});
            }
        }

       return ans; 
    }
};