class Solution {
public:
    int getFact(int n){
        if(n<=1) return n;
        return n* getFact(n-1);
    }

    void func(set<int>&s, string&str, int& k){
        
        int sz = s.size();
        
        if(sz==1){
            str+= to_string((*s.begin()));
            k=0;
            return;
        }


        int fact = getFact(sz-1);
      
        int a= k/fact;
         k= k%fact;
        
        auto it = s.begin();
        advance(it, a);
        str+= to_string((*it));
        s.erase(it);
    }

    string getPermutation(int n, int k) {
            //kth permutation
            k--;
            set<int>s;
            string str="";
            for(int i=1;i<=n;i++)s.insert(i);

            while(str.size()<n){
                func(s, str, k);
            }
        return str;
    }
};
//n * (n-1)!

//2nd index wala ayga

// 2.       134
// 2 2 2

//
//2134
//2143
//2314