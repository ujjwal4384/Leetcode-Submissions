class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>tail;
        //tail[i]= stores last smallest element for subsequenece of length i+1.
        //it does not store correct subsequence, just helpful for length.
        vector<int>par(n, -1);
        vector<int>tail_indices;
        for(int i=0;i<n;i++){
                
                int pos = lower_bound(tail.begin(), tail.end(), nums[i]) - tail.begin();
                if(pos>0){
                    par[pos] = tail_indices[pos-1];
                }
                if(pos == tail.size()){
                    tail.push_back(nums[i]);
                    tail_indices.push_back(i);
                    continue;
                }
                //overwrite that index with this value
                
                tail[pos] = nums[i];
                tail_indices[pos] = i;
        }
        vector<int>ans;
        int cur = tail_indices.back();
        while(cur != -1){
            ans.push_back(nums[cur]);
            cur = par[cur];
        }
        reverse(ans.begin(), ans.end());
        for(auto&x:ans){
            cout<<x<<" ";
        }    
        return tail.size();
    }
};
/*

 1 7 8 4 9

 1->[1]
 7->[1, 7]
 8->[1, 7, 8]
 4 -> not greater than end of tail hence find just greater eq element and overwrite that
    -> [1, 4, 8] //Note 1 4 8 is not correct subsequence as 4 comes after 8 in array but it gives correct LIS length because we know if 8 is there there was some element smaller than 8 (7) before. not concerned on what that element was. 
5-> [1,4,8, 9] ans = 4 .tail.size()

Now what if you want longest subequence also in O(nLogn)?
Then need to store parent array info.
*/