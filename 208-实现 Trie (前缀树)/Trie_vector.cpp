#include <string>
#include <vector>
using namespace std;

// 使用 vector 保存子结点指针
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for (const auto &c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for (const auto &c : word) {
            if (node->children[c - 'a'] == nullptr) {
                return false;
            }
            node = node->children[c - 'a'];
        }

        return node->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (const auto &c : prefix) {
            if (node->children[c - 'a'] == nullptr) {
                return false;
            }
            node = node->children[c - 'a'];
        }

        return true;
    }

private:
    static const int MAX_CHILDREN = 26;

    struct TrieNode {
        bool isWord;
        vector<TrieNode*> children;
        TrieNode() : isWord(false), children(MAX_CHILDREN) {}
    };

    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */