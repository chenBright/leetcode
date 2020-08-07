# 460-LFU缓存

## 题目

leetcode：[460-LFU缓存](https://leetcode-cn.com/problems/lfu-cache/)

## 哈希表 + 红黑树

参考[LeetCode LRU缓存官方解答](https://leetcode-cn.com/problems/lfu-cache/solution/lfuhuan-cun-by-leetcode-solution/)。

```c++
struct Node {
    int count;
    int time;
    int key;
    int val;

    Node(int c, int t, int k, int v) : count(c), time(t), key(k), val(v) {}
};

struct compare {
    // 先比较 count，后比较 time
    bool operator()(Node* a,  Node* b) {
        return a->count == b->count ? a->time < b->time : a->count < b->count;
    }
};

class LFUCache {
private:
    int time; // 只需表明操作的先后顺序，使用自增的方式即可。
    int cap;
    set<Node*, compare> nodeSet;
    unordered_map<int, Node*> keyToNode;

public:
    LFUCache(int capacity) : cap(capacity) {
        assert(capacity > 0);
    }

    int get(int key) {
        if (keyToNode.count(key) == 0) {
            return -1;
        }

        auto node = keyToNode[key];
        nodeSet.erase(node);

        ++node->count;
        node->time = ++time;

        nodeSet.insert(node);

        return node->val;
    }

    void put(int key, int value) {
        ++time;
        if (keyToNode.count(key) == 0) {
            if (nodeSet.size() == cap) {
                auto minNode = *nodeSet.begin();
                keyToNode.erase(minNode->key);
                nodeSet.erase(nodeSet.begin());

                delete minNode;
            }

            auto node = new Node(1, time, key, value);
            keyToNode[key] = node;
            nodeSet.insert(node);
        } else {
            auto node = keyToNode[key];
            nodeSet.erase(node);

            ++node->count;
            node->time = ++time;
            node->val = value;

            nodeSet.insert(node);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

## 双哈希表

```c++
struct Node {
    int key;
    int val;
    int freq;

    Node(int k, int v, int f) : key(k), val(v), freq(f) {}

};

class LFUCache {
private:
    int minfreq;
    int cap;
    // key：频率，val：链表，链表头结点是最新访问过的结点，链表尾结点是最久访问过的结点
    unordered_map<int, list<Node> > freqTable;
    unordered_map<int, list<Node>::iterator> keyTable; // <键值，链表中的指针>

public:
    LFUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        if (cap == 0 || keyTable.count(key) == 0) {
            return -1;
        }

        auto node = keyTable[key];
        int freq = node->freq;
        int val = node->val;
        freqTable[freq].erase(node);
        if (freqTable[freq].empty()) {
            freqTable.erase(freq);
            if (minfreq == freq) {
                ++minfreq;
            }
        }

        ++freq;
        freqTable[freq].push_front(Node(key, val, freq));
        keyTable[key] = freqTable[node->freq].begin();

        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }

        if (keyTable.count(key) == 0) {
            if (keyTable.size() == cap) {
                auto node = freqTable[minfreq].back();
                keyTable.erase(node.key);
                freqTable[minfreq].pop_back();
                if (freqTable[minfreq].empty()) {
                    freqTable.erase(minfreq);
                }
            }

            minfreq = 1;
            freqTable[1].push_front(Node(key, value, 1));
            keyTable[key] = freqTable[1].begin();
        } else {
            auto node = keyTable[key];
            int freq = node->freq;
            freqTable[freq].erase(node);
            if (freqTable[freq].empty()) {
                freqTable.erase(key);
                if (minfreq == freq) {
                    ++minfreq;
                }
            }
            ++freq;
            freqTable[freq].push_front(Node(key, value, freq));
            keyTable[key] = freqTable[freq].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```