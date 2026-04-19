class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size(), m = pattern.size();
        int window = m+1;
        int count =0;
        //check all subarrays of length window which satisfy the usecase
        for(int i=0; i<n; i++){
               if(i+ window-1 >=n) break;
               int j =0;
               bool valid = true;
               for(int k=i; k<=i+window-1; k++){
                    if(j==m)break;
                    bool a = pattern[j]==1 && nums[k] < nums[k+1];
                    bool b = pattern[j]==0 && nums[k] == nums[k+1];
                    bool c = pattern[j]==-1 && nums[k] > nums[k+1];
                    if(a || b || c){
                        j++;
                    }else{
                        valid = false;
                        break;
                    }
               }
               count += valid;   
        }
        return count;
    }
};