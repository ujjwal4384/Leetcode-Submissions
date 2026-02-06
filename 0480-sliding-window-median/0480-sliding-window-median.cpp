class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        //Pattern: Sliding window dynamic top W = k/2 
        //Startegy: 2 multisets. miniSet, waitingSet(reserve)
        int n= nums.size();
        multiset<int, greater<int>>left;
        multiset<int>right;
        vector<double>ans;
        int w = (k+1)/2;
        for(int i=0;i<n;i++){
            //add greedily in mini then balance
             left.insert(nums[i]);
        
             //balance   
             if(left.size() > w){
                right.insert(*left.begin()); 
                left.erase(left.begin());
             }

             //remove: slide window if i>=w
             if(i>=k){
                int toRem = nums[i-k];
                if(left.find(toRem) != left.end()){
                   left.erase(left.find(toRem));
                   left.insert(*right.begin());
                   right.erase(right.begin());
                }else{
                    right.erase(right.find(toRem));
                }
             }
            if(i>=k-1){
                if(k%2){
                    ans.push_back(*left.begin());
                }else{
                    int x = *left.begin(); int y = *right.begin() ;
                    ans.push_back((0LL + x+y)/2.0);
                }
            }
        }

        return ans;
    }
};