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