# 220-存在重复元素 III

## 题目

leetcode：[220-存在重复元素 III](https://leetcode-cn.com/problems/contains-duplicate-iii/)

## 自平衡二叉搜索树

参考[LeetCode官方题解](https://leetcode-cn.com/problems/contains-duplicate-iii/solution/cun-zai-zhong-fu-yuan-su-iii-by-leetcode)。使用`set`或者`map`来维护滑动窗口，因为`set`和`map`底层是用红黑树实现的。

### 实现1

遍历数组，每次遍历到的元素为`x`：

1. 如果树的大小超过了k*k*, 则移除最早加入树的那个数。
2. 在`set`查找小于等于`x`的最大数字`m`，如果`x - m <= t`，则返回true；
3. 在`set`查找大于等于`x`的最小数字`n`，如果`n - x <= t`，则返回true；
4. 在 `set` 中插入`x`；

遍历完数组，没有找到符合条件的数字，则返回false。

时间复杂度：***O(nlog(min(n,k)))***。需要遍历这个`n`长度的数组。对于每次遍历，在`ste`中搜索，插入 或者删除操作的时间复杂度为***O(logmin(k,n))***。

空间复杂度：***O*(min(n,k))***。

```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            // 保持滑动窗口的大小为 k
            if (s.size() > k) {
                s.erase(nums[i - k - 1]);
            }

            auto lowerIt = maxLower(s, nums[i]);
            // 找到小于等于 tarnums[i] 的最大的数，且 nums[i] - 该数 <= t，则符合条件
            if (lowerIt != s.end() && nums[i] - *lowerIt <= t) {
                return true;
            }

            auto upperIt = minUpper(s, nums[i]);
            // 找到大于等于 tarnums[i] 的最小的数，且 该数 - nums[i] <= t，则符合条件
            if (upperIt != s.end() && *upperIt - nums[i] <= t) {
                return true;
            }

            s.insert(nums[i]);
        }

        return false;
    }

private:
    // 找到小于等于 target 的最大的数
    set<long>::iterator maxLower(set<long> &s, int target) {
        if (s.empty()) {
            return s.end();
        }

        auto it = s.lower_bound(target);
        if (it == s.begin()) {
            if (*it == target) { // 第一个元素等于 target，则返回 begin()
                return it;
            } else { // 没有小于等于 target 的数，则返回 end()
                return s.end();
            }
        }

        // 前一个迭代器才是指向小于等于 target 的最大的数
        return --it;
    }

    // 找到大于等于 target 的最小的数
    set<long>::iterator minUpper(set<long> &s, int target) {
        if (s.empty()) {
            return s.end();
        }

        auto it = s.upper_bound(target);
        if (it == s.begin()) {
            return it;
        }

        // 如果前一个迭代器指向的数字等于 target，则指向前一个
        if (*--it != target) {
            ++it;
        }

        return it;
    }
};
```

### 实现2

遍历数组，每次遍历到的元素为`x`：

1. 如果树的大小超过了k*k*, 则移除最早加入树的那个数。

2. 在`set`查找小于等于`x - t`的最大数字`m`，如果`abs(x - m )<= t`，则返回true；

   因为小于 nums[i] - t 部分肯定不符合条件，只要验证大于等于部分即可。证明如下：

   ```
   设 x < nums[i] - t，则 -x > nums[i] - t
   nums[i] - x > nums[i] - nums[i] + t = t
   ```

3. 在 `set` 中插入`x`；

遍历完数组，没有找到符合条件的数字，则返回false。

该方法的时空复杂度同上。

```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<long> s;
        for (int i = 0; i < nums.size(); ++i) {
            // 保持滑动窗口的大小为 k
            if (s.size() > k) {
                s.erase(nums[i - k - 1]);
            }

            // 找到第一个大于等于 nums[i] - t 的数
            auto it = s.lower_bound(static_cast<long>(nums[i]) - t);
            // 小于 nums[i] - t 部分肯定不符合条件，只要验证大于等于部分即可
            // 证明：设 x < nums[i] - t，则 -x > nums[i] - t
            // nums[i] - x > nums[i] - nums[i] + t = t
            if (it != s.end() && abs(nums[i] - *it) <= t) {
                return true;
            }

            s.insert(nums[i]);
        }

        return false;
    }
};
```

## 桶排序

参考[LeetCode官方题解](https://leetcode-cn.com/problems/contains-duplicate-iii/solution/cun-zai-zhong-fu-yuan-su-iii-by-leetcode)。

```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (nums.empty() || t < 0) {
            return false;
        }

        unordered_map<long, long> m;
        long bucketSize = static_cast<long>(t) + 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.size() > k) {
                m.erase(getBucketId(nums[i - k - 1], bucketSize));
            }

            long id = getBucketId(nums[i], bucketSize);
            // 如果桶内已经有元素，则这两个数字肯定符合条件
            if (m.find(id) != m.end()) {
                return true;
            }
            // 检查与相邻桶内元素是否满足条件
            if (m.find(id + 1) != m.end() && abs(nums[i] - m[id + 1]) <= t) {
                return true;
            }
            if (m.find(id - 1) != m.end() && abs(nums[i] - m[id - 1]) <= t) {
                return true;
            }

            m[id] = nums[i];
        }

        return false;
    }

private:

    long getBucketId(long value, long bucketSize){
        return value < 0 ? (value + 1) / bucketSize - 1 : value / bucketSize;
    } 
};
```

