class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();

        map<char,int>f1,f2;
        for(int i=0;i<n;i++){
            char ch = s1[i];
            f1[ch]++;
            bool isEvenPos = (i%2==0);
            bool found = false;
            for(int j=0;j<n;j++){
                if(i==0)f2[s2[j]]++;
                if(isEvenPos && (j%2==0) && s2[j]==ch){
                    found = true;
                }
                else if(!isEvenPos && (j%2) && s2[j]==ch){
                    found = true;
                }
            }
            if(found==false) return false;
        }

        for(auto &p:f1){
            if(f2[p.first] != p.second) return false;
        }
        return true;
    }
};