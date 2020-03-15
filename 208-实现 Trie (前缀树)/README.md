# 208-实现 Trie (前缀树)

## 题目

leetcode：[208-实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)

## Trie (前缀树)

Trie树的概念可以参考[博客](http://dongxicheng.org/structure/trietree/)。

注意：每个结点需要一个变量来标示该结点是否是一个单词的结尾字母。

### 使用数组保存子结点指针

```c++
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
        TrieNode *children[MAX_CHILDREN];
        TrieNode() : isWord(false), children({nullptr}) {}
    };

    TrieNode *root;
};
```

### 使用vector保存子结点指针

用vector保存子结点指针比用数组保存，执行速度慢很多。

```c++
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
```

###  使用哈希表保存子结点指针

用哈希表保存子结点指针比用数组保存，执行速度同样慢很多；但使用 vector 但比快了。

在内存占用方面，该方法是三种方法中，内存占用最少的。

```c++
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : root(new TrieNode()) {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for (const auto &c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for (const auto &c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }

        return node->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (const auto &c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }

        return true;
    }

private:
    static const int MAX_CHILDREN = 26;

    struct TrieNode {
        bool isWord;
        unordered_map<char, TrieNode*> children;
        TrieNode() : isWord(false) {}
    };

    TrieNode *root;
};
```

