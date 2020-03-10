#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

class LRUCache {
public:
    using ListType = list<int>; // list<key>
    using MapType = unordered_map<int, int>; // <key, value>

    LRUCache(int capacity) : capacity_(capacity) {

    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        // 将要读取的元素放到列表头部
        l.splice(l.begin(), l, find(l.begin(), l.end(), key));
        return m[key];
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            l.splice(l.begin(), l, find(l.begin(), l.end(), key)); // 将结点移动到双向链表的头部
        } else {
            l.push_front(key); // 在双向链表中插入新元素
        }

        // 先插入新元素
        // 如果插入新元素之后，元素个数大于缓冲器容量，则需要删除最近最少使用的元素
        m[key] = value;
        if (m.size() > capacity_) {
            int oldestKey = l.back();
            l.pop_back();
            m.erase(m.find(oldestKey));
        }
    }

private:
    ListType l;
    MapType m;
    int capacity_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
