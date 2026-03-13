class Solution {
    bool isValid(long long t, int n, vector<int>&wt){
            int h = n;
            long long heightCut = 0;
            for(auto w: wt){
                 // x(x+1)/2 *w <=t   find x. (height it can reduce wihtin t seconds)
                 //quDRATIC roots FORMAULA: -b+sqrt(b^2 - 4ac) /2a ;
                 long double val = (1 + (8.0L * t)/w ); 
                 long double root = (-1.0L + sqrtl(val))/2.0L ;
                 heightCut += root; 
                 if(heightCut >= n) return 1;
            }
            return heightCut >= n;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        sort(workerTimes.begin(), workerTimes.end());
        
    long long l = 0, r = 1LL* workerTimes[0]*(mountainHeight * (mountainHeight+1LL))/2LL ;
        long long ans = r;
        while(l<=r){
            long long mid = l + ((r-l)>>1LL);
            bool flag =isValid(mid, mountainHeight, workerTimes);
            if(flag){
                ans = mid;
                r = mid -1 ;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};