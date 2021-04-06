#include <bits/stdc++.h>

using namespace std;
class Trie {    
private:
    struct TrieNode{
        bool isword;
        vector<TrieNode*> children;
        TrieNode(): isword(false), children(26){};
        ~TrieNode(){
            for (auto* node : children){
                delete node;
            }
        }
    };
    
    unique_ptr<TrieNode> _root;
    
    const TrieNode* find(const string& s) const{
        const TrieNode* p = _root.get();
        for (const char c: s){
            p = p -> children[c - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }
public:
    /** Initialize your data structure here. */
    
    Trie():_root(new TrieNode()) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = _root.get();
        for (const char & c : word){
            if (!p -> children[c - 'a'])
                p -> children[c - 'a'] = new TrieNode();
            p = p -> children[c - 'a'];
        }
        p -> isword = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto* p = find(word);
        return (p != nullptr) && p -> isword;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto* p = find(prefix);
        return p != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */