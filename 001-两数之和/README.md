# 001-两数之和

## 题目

leetcode：[001-两数之和](https://leetcode-cn.com/problems/two-sum/)


## 暴力法
```c++
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int sum = nums[i] + nums[j];
                if (sum == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }

        return result;
    }
};
```

## 哈希表

### 两次循环

```c++
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        // <值, 索引>
        unordered_map<int, int> hashMap;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            hashMap.insert(make_pair(nums[i], i));
        }

        for (int i = 0; i < len; ++i) {
            int anotherNum = target - nums[i]; // 另一个数
            // 存在等于 target - nums[i] 的数且不是同一个数
            if (hashMap.count(anotherNum) && i != hashMap[anotherNum]) {
                result.push_back(i);
                result.push_back(hashMap[anotherNum]); // 另一个数的索引
                break;
            }
        }

        return result;
    }
};
```

### 一次循环

```c++
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result;
        // <值, 索引>
        unordered_map<int, int> hashMap;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int anotherNum = target - nums[i]; // 另一个数

            // 存在等于target - nums[i]的数且不是同一个数
            // 否则，插入记录到哈希表
            if (hashMap.count(anotherNum)) {
                result.push_back(i);
                result.push_back(hashMap[anotherNum]); // 另一个数的索引
                break;
            } else {
                hashMap.insert(make_pair(nums[i], i));
            }
        }

        return result;
    }
};
```

