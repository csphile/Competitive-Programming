#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    long long m = 1;
    int trie[200001][26];
    int cnt[200001][26];
public:
    /** Initialize your data structure here. */
    Trie() {
        memset(trie, 0, sizeof(trie));
        memset(cnt, 0, sizeof(cnt));
    }
    
    long long find(string s){
        int u = 0;
        for (const char& c: s){
            u = trie[u][c - 'a'];
            if (!u)
                return 0;
        }
        return u;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int u = 0;
        for (const char& c: word){
            if (!trie[u][c - 'a'])
                trie[u][c - 'a'] = m++;
            u = trie[u][c - 'a'];
        }
        cnt[u][word.back() - 'a'] += 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto u = find(word);
        return (u && cnt[u][word.back() - 'a']);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */