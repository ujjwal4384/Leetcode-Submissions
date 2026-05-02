class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n= seats.size();
        vector<int>occupied;
        for(int i=0;i<n;i++){
            if(seats[i])occupied.push_back(i);
        }

        int sz = occupied.size();   
        int max_zeroes_block = 0;
       
        for(int i=1;i<sz; i++){
            int cur_block = occupied[i] - occupied[i-1] - 1;
            max_zeroes_block = max(max_zeroes_block, cur_block);
        }

        int cand1 = max_zeroes_block <=2 ? 1: (max_zeroes_block+1)/2 ;
        //for first and last one: 
        int cand2 = occupied.front() ;

        int cand3 = (n -1) - occupied.back() ;
        
        
        return max({cand1, cand2, cand3});

    }
};