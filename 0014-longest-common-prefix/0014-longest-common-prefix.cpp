class Trie{
   public: map<char, Trie*>children;
   public: bool isLeaf;
   public: int childCount;

   public: Trie(){
        for(char ch='a';ch<='z';ch++)children[ch]=NULL;
        isLeaf= false;
        childCount=0;
    }
    int getChildCount(){
        return childCount;
    }
   char getChild(){
    for(char ch='a';ch<='z';ch++){
        if(children[ch]) return ch;
    }
    return 'z';
   }
   int search(Trie* root, string& key){
        if(!root) return 0;
            Trie* node = root;
            
            for(int j=0;j<key.size();j++){
                char ch = key[j];
                char i = ch;
                if(node->children[i]){
                 node = node->children[i]; 
                }else{
                 return j+1;
                }  
            }
            return key.size() ;
    }
   void insert(Trie* root, string & key){
        if(!root) return;
            Trie* node = root;
            
            for(int j=0;j<key.size();j++){
                char ch = key[j];
                char i = ch;
                if(node->children[i]){
                  
                 if(j==key.size()-1){
                     node->children[i]->isLeaf= true;
                 }
                 
                }else{
                 node->childCount ++;
                 Trie* newNode = new Trie();
                 node->children[i] = newNode;
                 if(j==key.size()-1){
                     newNode->isLeaf= true;
                 }else{
                     newNode->isLeaf= false;
                 }
                }  
                node = node->children[i];
            }
            node->isLeaf=true;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        Trie* root = new Trie();
        for(int i=0;i<n;i++){
            root->insert(root, strs[i]);
        }
        int c = 0;
        string s = strs[0];
        while(c< s.size()){
            int x = root->getChildCount();
            char p = root->getChild();
            bool isLeaf= root->isLeaf;
          
            if(x!=1 || p!=s[c] || isLeaf) break;
            c++;
            
            root = root->children[p];

        }
       return s.substr(0, c); 
    }
};