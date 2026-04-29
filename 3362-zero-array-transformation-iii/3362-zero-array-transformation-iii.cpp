class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        // move l->r, at ith index you should have atleast >= nums[i] queries.
        //so that it can be made 0.
        //quereis availabe from ith index. => l=i.
        vector<vector<int>>available_at(n);
        for(int i=0;i<q;i++){
            int l=queries[i][0], r= queries[i][1];
            available_at[l].push_back(r);
        }
        priority_queue<int, vector<int>>pq;
        vector<int>diff(n+1, 0);
        int coverage = 0;
        int queries_used = 0;
        for(int i=0;i<nums.size();i++){
                coverage += diff[i]; //substract dropoffs of queries ennding before i.
                for(auto en: available_at[i]){
                    pq.push(en);
                }
                while(coverage < nums[i]){
                        if(pq.empty() || pq.top() < i) return -1;
                        int en = pq.top();
                        pq.pop();
                        coverage ++;
                        diff[en+1]--;
                        queries_used++;
                } 
        }

      return q - queries_used;  
    }
};