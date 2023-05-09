class Trie {
    private:
    vector<Trie*> children;
    bool isEnd=false;
public:
    /** Initialize your data structure here. */
    Trie() :children(26), isEnd(false) {
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node=this;
        for(char c:word){
            int num=c-'a';
            if(!node->children[num]) node->children[num]=new Trie();
            node=node->children[num];

        }
        node->isEnd=true;

    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node=this;
        for(char c:word){
            int num=c-'a';
            if(node->children[num]!=nullptr){
                node=node->children[num];
            }else return false;

        }
        return node->isEnd;

    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node=this;
        for(char c:prefix){
            int num=c-'a';
            if(node->children[num]!=nullptr){
                node=node->children[num];
            }else return false;

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
