class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        int sum =0;
        for(auto&x:nums)sum += x;

        map<int, vector<int>>left, right;



        int k = (1<<(N/2));
        for(int i=0;i<k;i++){
            
            int lSum=0,rSum=0;
            int sz =0;
            for(int j=0;j<N/2; j++){
                int x = nums[j], y= nums[j+N/2];
                
                int a = i & (1<<j) ;
                
                if(a){
                    lSum +=x;
                    rSum +=y;
                    sz++;
                }
            }
            
            left[sz].push_back(lSum);
            right[sz].push_back(rSum);
        }

       

        int part1Sum = INT_MIN;

        for(auto & p: left){
            int sz = p.first;
            vector<int>l =p.second;
            vector<int>r =right[N/2 - sz];
            sort(r.begin(), r.end());
          
           sort(l.begin(), l.end());
            for(auto &x : l){
                int target = sum/2 - x;
                auto it = lower_bound(r.begin(), r.end(), target);
                
                if(it == r.end() || (*it) != target){
                    it--;
                }
                if(it == (--r.begin())) continue; 
                

                int y = (*it);
                part1Sum = max(part1Sum, x + y);
            }

        }


   return abs(sum - 2* part1Sum);
  //  return 0;
    }
};