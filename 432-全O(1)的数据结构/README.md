# 432-全O(1)的数据结构

## 题目

leetcode：[432-全O(1)的数据结构](https://leetcode-cn.com/problems/all-oone-data-structure/submissions/)

## 双向链表 + 哈希表

```c++
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (m_.count(key) == 0) {
            if (l_.empty() || l_.front().first != 1) {
                l_.push_front(make_pair(1, unordered_set<string>{key}));
            } else {
                l_.front().second.insert(key);
            }
            m_[key] = l_.begin();
        } else {
            changeKey(key, 1);
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (m_.count(key) != 0) {
            if (m_[key]->first == 1) {
                m_[key]->second.erase(key);
                checkEmpty(m_[key]);
                m_.erase(key);
                return;
            }

            changeKey(key, -1);
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return m_.empty() ? "" : *(l_.back().second.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return m_.empty() ? "" : *(l_.front().second.begin());
    }
private:
    using ListType = list<pair<int, unordered_set<string>>>;
    using MapType = unordered_map<string, ListType::iterator>;

    ListType l_;
    MapType m_;

    void changeKey(string key, int offset) {
        auto it = m_[key];
        int newNum = it->first + offset;
        auto newIt = it;
        if (offset == 1) {
            it = newIt++;
        } else {
            it = newIt--;
        }
        it->second.erase(key);
        if (newIt != l_.end() && newNum == newIt->first) {
            newIt->second.insert(key);
            m_[key] = newIt;
        } else {
            if (offset == 1) {
                m_[key] = l_.insert(newIt, make_pair(newNum, unordered_set<string>{key}));
            } else {
                m_[key] = l_.insert(it, make_pair(newNum, unordered_set<string>{key}));
            }
        }
        checkEmpty(it);
    }

    void checkEmpty(ListType::iterator it) {
        if (it->second.empty()) {
            l_.erase(it);
        }
    }
};
```

