#include <unordered_map>
#include <set>
#include <cassert>
using namespace std;

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