# 211-添加与搜索单词 - 数据结构设计

## 题目

leetcode：[211-添加与搜索单词 - 数据结构设计](https://leetcode-cn.com/problems/add-and-search-word-data-structure-design/)

## Trie树

参考[208-实现 Trie (前缀树)](../208-实现 Trie (前缀树)/)，唯一需要修改的是，在搜索的时候遇到`.`，则需要查找所有子树。可以使用DFS处理。

```c++
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
```



