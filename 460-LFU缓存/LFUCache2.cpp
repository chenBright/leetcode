#include <unordered_map>
#include <list>
#include <cassert>
using namespace std;

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