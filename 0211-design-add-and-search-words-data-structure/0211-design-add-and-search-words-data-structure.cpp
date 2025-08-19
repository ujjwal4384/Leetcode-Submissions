struct TrieNode{
    unordered_map<char,TrieNode*>mp;
    bool isEnd;
  
    TrieNode(){
     isEnd = false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
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
       return _search(word,0, root);
    }

    bool _search(string& word, int id, TrieNode* node){
        if(node == NULL) return false;
        if(id == word.size()) return node->isEnd;
        char ch = word[id];    
        if(ch=='.'){
            for(char k='a';k<='z';k++){
                if(node->mp[k] && _search(word, id+1, node->mp[k])) return true;
            }
            return false;
        }else{
            if(node->mp[ch] == NULL) return false;
            return _search(word, id+1, node->mp[ch]);    
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */