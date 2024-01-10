class Solution {
public:
    void nextPermutation(vector<int>& v) {
      
        //1 4 7 3 6 5 2 -> (swap 5<->3)-> 1 4 7 5 6 3 2 ->(reverse all numbers after 5) -> 1 4 6 5 2 3 6 
         int n= v.size();
         
         int pi=-1;
         for(int i=n-1;i>=0;i--){
             if(i>=1 && v[i-1]<v[i]){
                 pi = i-1;
                 break;
             }
         }
         //handles decreasing order case and single number case
         if(pi==-1){
             reverse(v.begin(),v.end());
             return;
         }
         //find minimum number between indices [pi+1, n-1] which is > v[pi]
         int pi2 = pi+1;
         for(int i =pi+1; i<n;i++){
             if(v[i]>v[pi]){
                 pi2=i;
             }
             else{
                  break;
             }
         }

         swap(v[pi], v[pi2]);
         int j=pi+1,k=n-1;
         while(j<k){
             swap(v[j],v[k]);
             j++;
             k--;
         }

      return;
    }
};