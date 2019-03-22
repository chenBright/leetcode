# 167-两数之和 II - 输入有序数组

## 题目

leetcode：[167-两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

## 二分查找

遍历一遍数组，根据当前遍历的数字，使用二分查找查找当前数字后面，是否存在另一个数字使得两数之和等于target。

该方法的时间复杂度为***O(nlogn)***。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        if (numbers.empty()) {
            return res;
        }

        for (int i = 0; i < numbers.size(); ++i) {
            int anotherNum = target - numbers[i];
            int index = binarySearch(numbers, i + 1, numbers.size() - 1, target - numbers[i]);
            // 查找成功
            if (index != -1) {
                res.push_back(i + 1);
                res.push_back(index + 1);
                break;
            }  
        }

        return res;
    }

private:
    // 二分查找，如果查找成功，则返回索引值；否则，返回 -1
    int binarySearch(vector<int> &numbers, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (numbers[mid] == target) {
                return mid;
            } else if (numbers[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1;
    }
};
```

## 双指针

使用两个指针遍历***有序***数组，一个指针（left）指向数组开头，一个指针指（right）向数组末尾：

1. 如果两个数组指向的元素之和等于target，则返回结果；
2. 如果两个数组指向的元素之和小于target，则***left向后移动，即++left***。
3. 如果两个数组指向的元素之和大于target，则***right向前移动，即—right***。

该方法的时间复杂度为***O(n)***。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        if (numbers.empty()) {
            return res;
        }

        int length = numbers.size();
        int left = 0;
        int right = length - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                res.push_back(left + 1);
                res.push_back(right + 1);
                break;
            } else if (sum > target) {
                --right;
            } else {
                ++left;
            }
        }

        return res;
    }
};
```

