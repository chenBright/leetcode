#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

class LRUCache {
public:
    using ListType = list<pair<int, int> >; // pair<key, value>
    using MapType = unordered_map<int, ListType::iterator>; // <key, ListType::iterator>

    LRUCache(int capacity) : capacity_(capacity) {

    }

    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }

        // 将要读取的元素放到列表头部。
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        // 当存在该 key 时，更新 value，并将结点移动到双向链表头部。
        if (it != m.end()) {
            it->second->second = value;
            l.splice(l.begin(), l, it->second);
            return;
        }

        // 先插入新元素。
        // 如果插入新元素之后，元素个数大于缓冲器容量，则需要删除最近最少使用的元素。
        l.push_front(make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > capacity_) {
            m.erase(m.find(l.back().first));
            l.pop_back();
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
