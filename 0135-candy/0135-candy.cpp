class Solution {
public:
    int candy(vector<int>& ratings) {
        int n= ratings.size();

        vector<int>candy(n, 1);

        for(int i=1; i<n; i++ ){
            if(ratings[i]>ratings[i-1]){
                candy[i] = candy[i-1] + 1;
            }
        }

        for(int i=n-2; i>=0; i-- ){
            if(ratings[i]>ratings[i+1]){
                candy[i] = max(candy[i], candy[i+1]+1);
            }
        }

        int sum =0;
        for(auto&x:candy)sum+=x;

        return sum;   
    }
};
  