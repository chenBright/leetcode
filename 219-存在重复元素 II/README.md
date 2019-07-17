# 219-存在重复元素 II

## 题目

leetcode：[219-存在重复元素 II](https://leetcode-cn.com/problems/contains-duplicate-ii/)

## 哈希表

时间复杂度：***O(n)***。 

空间复杂度：***O(min(n,k))***。

```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> m; // <元素, 元素索引>
        for (int i = 0;  i < nums.size(); ++i) {
            if (m.find(nums[i]) != m.end()) {
                if (i - m[nums[i]] <= k) {
                    return true;
                }
            }
            m[nums[i]] = i;
        }

        return false;
    }
};
```

## 自平衡二叉搜索树

使用底层实现为红黑树的`set`来维护一个最大容量为`k`的滑动窗口。

遍历数组，便利到的元素为`x`：

1. 如果`ste`的大小超过了k, 则移除最早加入树的那个数。
2. 在`set`中查找`x`，如果查找成功，则返回true。

遍历完数组，没有找到符合条件的数字，则返回false。

时间复杂度：***O(nlog(min(k,n)))***。 

空间复杂度：***O(min(n,k))***。

```c++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        set<int> s; // 滑动窗口 <元素>
        for (int i = 0;  i < nums.size(); ++i) {
            // 保持滑动窗口的大小为 k
            if (s.size() > k) {
                s.erase(nums[i - k - 1]);
            }
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }

        return false;
    }
};
```

