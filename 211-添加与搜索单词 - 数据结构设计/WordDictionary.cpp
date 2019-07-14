#include <string>
using namespace std;

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() : root(new TrieNode()) {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *node = root;
        for (const auto &c : word) {
            if (node->children[c - 'a'] == nullptr) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root, 0);
    }

private:
    static const int MAX_CHILDREN = 26;

    struct TrieNode {
        bool isWord;
        TrieNode *children[MAX_CHILDREN];
        TrieNode() : isWord(false), children({nullptr}) {}
    };

    TrieNode *root;

    bool search(string &word, TrieNode *node, int i) {
        if (i == word.size()) {
            return node->isWord;
        }

        char c= word[i];
        if (c == '.') { 
            // 遇到 “.”，需要遍历所有字母
            for (const auto &child : node->children) {
                if (child != nullptr && search(word, child, i + 1)) {
                    return true;
                }
            }
            return false;
        } else {
            return node->children[c - 'a'] && search(word, node->children[c - 'a'], i + 1);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */