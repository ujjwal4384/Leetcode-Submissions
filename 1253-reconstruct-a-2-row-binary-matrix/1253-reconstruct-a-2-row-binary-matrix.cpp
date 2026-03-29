class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>>ans2;
        vector<vector<int>>ans(2, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            int x = colsum[i];
            if(x == 0){
                ans[0][i] = 0, ans[1][i] = 0;
            }
            else if(x == 2){
                if(upper <=0 || lower <=0) return ans2;
                ans[0][i] = 1, ans[1][i] = 1;
                upper --; lower --;
            }else if(x == 1){
                if(upper >= lower){
                    if(upper<=0) return ans2;
                    ans[0][i] = 1, ans[1][i] = 0;
                    upper --;
                }else{
                    if(lower<=0) return ans2;
                    ans[0][i] = 0, ans[1][i] = 1;
                    lower --;
                }
            }
        }
        return lower ==0 && upper == 0 ? ans : ans2;
    }
};