//
// Created by bin gao on 2019-10-04.
//

class Trie {
public:
    /** Initialize your data structure here. */
    struct Node{
        bool is_end;
        Node *son[26];
        Node(){
            is_end = false;
            for(int i = 0; i < 26; i++) son[i] = NULL;
        }
    } *root;

    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for(auto c: word){
            int u = c - 'a';
            if(p -> son[u] == NULL) p -> son[u] = new Node();
            p = p -> son[u];
        }
        p -> is_end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for(auto c: word){
            int u = c - 'a';
            if(p -> son[u] == NULL) return false;
            else p = p -> son[u];
        }
        return p -> is_end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for(auto c: prefix){
            int u = c - 'a';
            if(p -> son[u] == NULL) return false;
            else p = p -> son[u];
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