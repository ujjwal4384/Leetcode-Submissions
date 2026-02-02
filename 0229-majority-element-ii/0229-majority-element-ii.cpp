class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = 3;
        map<int,int>candidates;
        for(auto x:nums){
            if(candidates.count(x) > 0 ) candidates[x]++;
            else {
                if(candidates.size() < k-1)candidates[x] = 1;
                else{
                    //remove one element from each of the candidates.
                    auto it = candidates.begin();
                    while(it != candidates.end()){
                        it->second --;
                        if(it->second ==0){
                            it = candidates.erase(it);//outpose empty, remove it
                        }else{
                            it++;
                        }
                    }
                }
            }
        }

    // Phase 2: The Verification
    for (auto& pair : candidates) pair.second = 0; // Reset counts for verification
    for (int num : nums) {
        if (candidates.count(num)) {
            candidates[num]++;
        }
    }
        
    vector<int>res;
    for(auto p:candidates){
            if(p.second > n/k)res.push_back(p.first);
     }
    return res;
 }
};