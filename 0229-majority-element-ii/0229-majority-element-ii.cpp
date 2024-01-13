class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
       
        int n=v.size();
        
       //there can be at max 2 such elements.
        
        //following algo finds most 2 frequent numbers in array.
        int cand1,cnt1=0;
        int cand2,cnt2=0;
        for(int i=0;i<n;i++){
            //cand1 ,cand2 do not compete with each other consider them fighting elections for different seats.
            if(cnt1==0&&v[i]!=cand2){
                cand1=v[i];
                cnt1=1;
               
            }
            else if(cnt2==0&&v[i]!=cand1){
                cand2=v[i];
                cnt2=1;
            }
            else if(v[i]==cand1){
               cnt1++;
            }
            else if(v[i]==cand2){
                cnt2++;
            }
            else{
                cnt1--,cnt2--;
            }
        }
        
        //check freq of these 2 elements which are potential candidates
        int freq1=0,freq2=0;
        for(auto&x:v){
            if(x==cand1)freq1++;
            else if(x==cand2)freq2++;
        }
        
        vector<int>ans;
        if(freq1>n/3)ans.push_back(cand1);
        if(freq2>n/3)ans.push_back(cand2);
        return ans;
    }
};