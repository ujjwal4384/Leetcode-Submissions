class Solution {
public:
    int hIndex(vector<int>& v) {
        
        int n = v.size();
        vector<int>papers(n+1, 0);
        for(auto& x: v){
            if(x>=n)papers[n]++;
            else papers[x]++;
        }
        int c =0;
        for(int h= n; h>=0 ;h--){
            c +=  papers[h];
            if(c >= h) return h;
        }

       return 0;

    }
};