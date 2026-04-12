class Solution {
public:
bool isValid(int k, vector<int>& piles, int& h){
    int hoursSpanned = 0;
    for(auto p:piles){
            int hrs = p/k + (p%k != 0);
            hoursSpanned += hrs;
            if(hoursSpanned>h) return false;
    }
    return true ;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h < piles.size()) return -1;
        int max_k = *max_element(piles.begin(), piles.end());//eats one pile every
       
        int l = 1, r = max_k;
        int ans = max_k;
        while(l<=r){
                int m = l + ((r-l)>>1);
                if(isValid(m, piles, h)){
                     ans = m;
                     r = m-1;
                }else l= m+1;
        }
        
       return ans;
    }
};