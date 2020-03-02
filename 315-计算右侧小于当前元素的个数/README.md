# 315-计算右侧小于当前元素的个数

## 题目

leetcode：[315-计算右侧小于当前元素的个数](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/)

## 思路

每个元素与其右侧小于当前元素的的元素，组成逆序对。

## 归并排序

排序可以看成是将逆序对转变成非逆序对额过程，所以可以使用排序的思想来统计逆序对。但是只能使用稳定的排序，而归并排序能满足这样的要求。

- 递归统计左边数组`[low, mid]`的逆序对；
- 递归统计右边数组`[mid + 1, high]`的逆序对；
- 统计两边组合成后的逆序对：
  - 当左边数组的元素**小于等于**右边数组的元素时，此时左边数组的元素与右边数组`[mid + 1, j]`都能组成逆序对；
  - 当右边数组已经归并完以后，左边数组剩下的元素右边数组所有的元素都能组成逆序对。

此方法中真正归并的是**索引数组**，不能归并元素数组。因为需要统计每个元素组成的逆序对的个数，并记录在数组中作为结果返回，如果归并了元素数组，则“丢失”了元素的索引信息。

详细的解析可参考[LeetCode题解](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/solution/gui-bing-pai-xu-suo-yin-shu-zu-python-dai-ma-java-/)。

时间复杂度：**O(nlogn)**。

空间复杂度：**O(n)**。

```c++
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length, 0);
        if (length == 0) {
            return result;
        }

        aux.reserve(length);
        vector<int> indexs(length); // 索引数组
        for (int i = 0; i < length; ++i) {
            indexs[i] = i;
        }

        mergeSort(nums, indexs, 0, static_cast<int>(nums.size()) - 1, result);

        return result;
    }

private:
    vector<int> aux;
    void mergeSort(vector<int>& nums, vector<int>& indexs, int low, int high, vector<int>& result) {
        if (low >= high) {
            return;
        }

        int mid = (low + high) / 2;
        mergeSort(nums, indexs, low, mid, result);
        mergeSort(nums, indexs, mid + 1, high, result);
        merge(nums, indexs, low, mid, high, result);
    }

    void merge(vector<int>& nums, vector<int>& indexs, int low, int mid, int high, vector<int>& result) {
        for (int k = low; k <= high; ++k) {
            aux[k] = indexs[k];
        }

        int i = low;
        int j = mid + 1;
        for (int k = low; k <= high; ++k) {
            if (i > mid) {
                indexs[k] = aux[j++];
            } else if (j > high) {
                indexs[k] = aux[i++];
                // 剩下的数比 [mid + 1, high] 对应的数都大，
                // 则逆序数为 high - mid
                result[indexs[k]] += high - mid;
            } else if (nums[aux[i]] <= nums[aux[j]]) {
                indexs[k] = aux[i++];
                // nums[aux[i]] 比 [mid + 1, j) 对应的数都大，
                // 则逆序数为 high - mid。
                result[indexs[k]] += j - mid - 1;
            } else {
                indexs[k] = aux[j++];
            }
        }
    }
};
```

