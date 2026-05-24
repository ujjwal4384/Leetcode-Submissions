class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        //sliding window: max window with atmax 2 distinct characters
        int l=0;
        int maxi =0;
        unordered_map<int,int>freq;
        for(int r=0;r<n;r++){
                int type = fruits[r];
                freq[type]++;
                while(freq.size() > 2){
                          int removeType = fruits[l];
                          freq[removeType]--;
                          if(freq[removeType] == 0)freq.erase(removeType);
                          l++;
                }    
                maxi = max(maxi, r-l+1);
        }
        return maxi;
    }
};