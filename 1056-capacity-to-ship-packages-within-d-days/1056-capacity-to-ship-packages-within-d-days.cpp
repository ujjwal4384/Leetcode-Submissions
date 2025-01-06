class Solution {
public:
    bool isValid(vector<int>& weights, int days, int k){
        int curSum = 0;
        int partitions =0;
        for(int i=0;i<weights.size(); i++){
            if(weights[i] > k){
                return false;
            }
            else if( weights[i] + curSum > k){
                partitions++;
                curSum = weights[i];
            }
            else{
                curSum+=weights[i];
            }
        }

        return partitions <= days-1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int maxi = 0, sum = 0;

        for(auto&x:weights){
            maxi=max(maxi, x);
            sum+=x;
        }

        int l = maxi, r= sum;
        int ans = r;
        while(l<=r){
            int mid = (l+r)/2;

            if(isValid(weights, days, mid)){
                ans = mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return ans;
    }
};