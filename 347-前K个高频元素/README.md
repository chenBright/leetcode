# 347-前K个高频元素

## 题目

leetcode：[347-前K个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

## 思路

该道题就是***TOP K***问题，不过要建立数字和字数之间的映射关系。

## 堆

时间复杂度：***O(nlog(k))***。

### 优先队列

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (const auto& n : nums) {
            ++m[n];
        }

        priority_queue<pair<int, int> > q;
        for (const auto& it : m) {
            q.push({it.second, it.first});
        }

        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = q.top().second;
            q.pop();
        }

        return result;
    }
};
```

### map

```
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计数字出现的次数
        unordered_map<int, int> m; // <数字， 次数>
        for (const auto& n : nums) {
            ++m[n];
        }

        // 桶排序
        vector<vector<int> > buckets(nums.size() + 1); // <次数，数字>
        for (const auto& it : m) {
            buckets[it.second].push_back(it.first); 
        }

        vector<int> result;
        for (int i = nums.size(); i >= 0; --i) {
            for (int j= 0; j < buckets[i].size(); ++j) {
                result.push_back(buckets[i][j]);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
```

## 桶排序

时间复杂度：***O(n)***。

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计数字出现的次数
        unordered_map<int, int> num2Count; // <数字， 次数>
        for (const auto& n : nums) {
            ++num2Count[n];
        }

        // 默认从小到大排序
        map<int, vector<int> > count2Num; // <次数，数字>
        for (const auto& it : num2Count) {
            count2Num[it.second].push_back(it.first);
        }

        vector<int> result;
        for (auto count2NumIt = count2Num.rbegin(); count2NumIt != count2Num.rend(); ++count2NumIt) {
            for (int i = 0; i < count2NumIt->second.size(); ++i) {
                result.push_back(count2NumIt->second[i]);
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};
```

## 快排`partition`

时间复杂度：***O(n)***。

```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计数字出现的次数
        unordered_map<int, int> m; // <数字， 次数>
        for (const auto& n : nums) {
            ++m[n];
        }

        vector<pair<int, int> > countAndNum(m.begin(), m.end()); // <次数，数字>
        findKth(countAndNum, 0, countAndNum.size() - 1, k - 1);

        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            result[i] = countAndNum[i].first;
        }

        return result;
    }

private:
    void findKth(vector<pair<int, int> >& countAndNum, int low, int high, int k) {
        int index = partition(countAndNum, low, high);

        if (index < k) {
            findKth(countAndNum, index + 1, high, k);
        } else if (index > k) {
            findKth(countAndNum, low, index - 1, k);
        }
    }

    int partition(vector<pair<int, int> >& countAndNum, int low, int high) {
        auto pivot = countAndNum[low];  // 基准元素
        while (low < high) {
            // 因为 low 位置的元素用于基准元素， low 位置先空出来，所以要先从后面开始找。

            // 从后面开始找，找到第一个不大于基准元素的元素
            while (low < high && countAndNum[high].second < pivot.second) {
                --high;
            }
            // 将其放到空出来的位置，此时 high 位置空出来了。
            countAndNum[low] = countAndNum[high]; 

            while (low < high && countAndNum[low].second >= pivot.second) {
                ++low;
            }
            // 将其放到空出来的位置，此时 low 位置空出来了。
            countAndNum[high] = countAndNum[low]; 
        }
        countAndNum[low] = pivot;
        return low; // 最后的位置 i == j 就是基准元素的最终位置
    }
};
```

