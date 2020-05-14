//Problem -> https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/
// Idea -> Basic Trie Implementation


struct TrieNode{
    bool isEnd;
    vector<TrieNode* > child;
    TrieNode() : isEnd(false), child(vector<TrieNode* >(26, NULL)) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto temp = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i]-97;
            if(!temp->child[idx])
                temp->child[idx] = new TrieNode();
            temp = temp->child[idx];
        }
        temp->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        bool ans = false;
        auto temp = root;
        for(int i=0;i<word.length();i++){
            int idx = word[i] - 97;
            if(temp->child[idx])
                temp = temp->child[idx];
            else
                return ans;
        }
        
        return temp->isEnd == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        bool ans = false;
        auto temp = root;
        for(int i=0;i<prefix.length();i++){
            int idx = prefix[i] - 97;
            if(temp->child[idx])
                temp = temp->child[idx];
            else
                return ans;
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
