# 146-LRU缓存机制

## 题目

leetcode：[146-LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)

## O(n)

使用双向链表记录在缓冲器中的`key`，但对特定`key`执行`get`或者`put`操作后，需要将该`key`对应的结点移到或者插入到队列头部，则队列尾部的结点便是最近做少使用的结点。

使用哈希表记录`key`和`value`，方便`get`操作。

`get`操作：

- 如果哈希表中不存在该`key`，则返回-1；
- 如果哈希表中存在该`key`，则
  - 在双向链表中找到值等于`key`的结点，并将该结点移动到双向链表头部；
  - 返回哈希表中该`key`对应的`value`。

`put`操作：

在哈希表中查找该`key`：

- 如果哈希表中不存在该`key`，则将新结点插入到双向链表头部；
- 哈希表中存在该`key`，则在双向链表中找到值等于`key`的结点，并将该结点移动到双向链表头部。

执行`m[key] = value`，该操作相当于对哈希表进行修改或者插入操作。

如果插入后`m.size() > capacity`，即元素个数超过个缓冲器的容量，则需要删除双向链表的尾结点，并删除尾结点对应的哈希表中的元素。



哈希表插入、读取和查找操作的时间复杂度都为**O(1)**，双向链表的查找操作的时间复杂度为**O(n)**，所以该实现的时间复杂度为**O(n)**。

```c++
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
```

## O(1)

要想在 **O(1)** 时间复杂度内完成这两种操作，必须使得查找的时间复杂度变为***O(1)***。

修改双向链表保存的类型为`pair<int, int>（<key, value>）`，即使用双向链表来保存`key`和·`value`。修改哈希表的`value`，使其保存`list<pair<int, int>>::iterator`，指向对应`key`在双向链表的迭代器，即在链表中的位置。查找的时候，先使用哈希表找到`key`对应的迭代器，根据迭代器找到对应的`value`，这一系列查找操作的时间复杂度为**O(1)**，所以最后该实现的时间复杂度为**O(1)**。

注意：如果使用的不是双向链表，而是单向链表，则移动结点的操作的时间复杂度为**O(n)**。因为单向链表的结点不知道自己的前置结点，必须通过遍历链表才能找到前置结点。

```c++
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
```

