class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size(), m =result.size();
        if(n!=m) return false;
        //L only moves left. R only moves right. 
        //L and R can never cross eachother. 
        //hence relative position of L and R will never change.
        //also position of L in result will always be <= that in start
        //and pos of R in result will always be >= that in start
        int i=0,j=0;
        while(i<n || j<n){
             while(i<n && start[i]=='X')i++;
             while(j<n && result[j]=='X')j++;
             if(i==n && j==n) return true;
             else if(i==n) return false;
             else if(j==n) return false;
             if(start[i] != result[j]) return false;
             if(start[i] =='L' && i< j) return false;
             if(start[i] =='R' && i> j) return false;
             i++, j++;
        }
        return true;
    }
};