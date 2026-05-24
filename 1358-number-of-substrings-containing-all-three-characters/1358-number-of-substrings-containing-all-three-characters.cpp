class Solution {
public:
    int numberOfSubstrings(string s) {
         int n = s.size();
         int k = 3;
       //sliding window: max window with atleast k=3 distinct characters
       int l=0;
       int count =0;
       unordered_map<char,int>freq;
       for(int r=0;r<n;r++){
               char ch = s[r];
               freq[ch]++;
               
               while(freq.size() == k){
                         count += (n-r);//from l->r it has 3 elements then fro sure from l->n-1 all subarray will also have 3 elements
                         char remove_ch = s[l];
                         freq[remove_ch]--;
                         if(freq[remove_ch] == 0)freq.erase(remove_ch);
                         l++;
               }   
               
       }
       return count;

    }
};