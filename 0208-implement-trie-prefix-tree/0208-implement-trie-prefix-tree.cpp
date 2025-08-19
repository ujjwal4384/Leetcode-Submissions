struct TrieNode{
    map<char,TrieNode*>mp;
    bool isEnd;
  
    TrieNode(){
     for(char ch='a'; ch<='z'; ch++){
          mp[ch] = NULL;
     }
     isEnd = false;
    }
};

class Trie {
private:
  TrieNode* root;
public:
    Trie() {
       root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(auto ch: word){
            if(temp->mp[ch] == NULL){
                temp->mp[ch] = new TrieNode();
            }    
            temp = temp->mp[ch];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(auto ch: word){
            if(temp->mp[ch] == NULL) return false;
            temp = temp->mp[ch];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(auto ch: prefix){
            if(temp->mp[ch] == NULL) return false;
            temp = temp->mp[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */