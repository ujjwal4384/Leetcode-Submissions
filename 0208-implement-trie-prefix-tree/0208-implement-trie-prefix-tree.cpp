class Trie {
private:
  map<char,Trie*>mp;
  bool isEnd;
public:
    Trie() {
       for(char ch='a'; ch<='z'; ch++){
          mp[ch] = NULL;
       }
       isEnd = false; 
    }
    
    void insert(string word) {
        Trie* temp = this;
        for(auto ch: word){
            if(temp->mp[ch] == NULL){
                temp->mp[ch] = new Trie();;
            }    
            temp = temp->mp[ch];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        Trie* temp = this;
        for(auto ch: word){
            if(temp->mp[ch] == NULL) return false;
            temp = temp->mp[ch];
        }
        return temp->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* temp = this;
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