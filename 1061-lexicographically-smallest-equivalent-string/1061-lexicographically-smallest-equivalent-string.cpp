class Dsu{
    int n;
    vector<int>par;
    // vector<int>rank;
  public:
    Dsu(int n){
        this->n = n;
        par.assign(n+1, 0);
        // rank.assign(n+1, 1);
        for(int i=0;i<=n;i++)par[i] = i;
    }

    void _union(int i, int j){
        int parI = findPar(i);
        int parJ = findPar(j);
        if(parI == parJ) return ;
        if(parI <parJ){
            par[parJ] = parI;
        }else{
            par[parI] = parJ;
        }
    }

    int findPar(int i){
        if(par[i]==i) return i;
        return par[i] = findPar(par[i]);
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {

        int n=s1.size();
        Dsu myDsu(26);
        for(int i=0;i<n;i++){
            int x = s1[i] - 'a', y = s2[i] - 'a';
            myDsu._union(x, y);
        }
        string ans = "";
        for(int i=0;i<baseStr.size(); i++){
              int node = baseStr[i] - 'a';
              int par = myDsu.findPar(node);
              ans += ('a' + par);
        }
        return ans;
    }
};