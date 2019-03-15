# 119-杨辉三角 II

## 题目

leetcode：[119-杨辉三角 II](https://leetcode-cn.com/problems/pascals-triangle-ii/)

## 迭代

这题与[118-杨辉三角](https://leetcode-cn.com/problems/pascals-triangle/)类似，不同点只是返回结果不同。

```c++
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> current(1, 1);
        if (rowIndex == 0) {
            return current;
        }

        vector<int> pre(current);
        vector<int>::iterator it;
        for (int i = 0; i < rowIndex; ++i) {
            for (it = pre.begin(); it != pre.end() && it + 1 != pre.end(); ++it) {
                int64_t temp = *it + *(it + 1); // 使用int64_t，避免整型溢出
                current.insert(current.end(), int(temp));
            }
            current.push_back(1); // 插入最后一个元素“1”
            pre = current;
            current.erase(current.begin() + 1, current.end()); // 只留下前面的元素“1”，其他元素都删除
        }

        return pre;
    }
};
```

## 二项式定理

使用[二项式定理](https://www.cnblogs.com/henry-1202/p/about_combinatorial_number.html)求第k行。

```c++
/**
 * 二项式定理
 * 参考
 * https://www.cnblogs.com/henry-1202/p/about_combinatorial_number.html
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(1, 1);
        int64_t temp = 1;
        ++rowIndex; // 从0开始
        for (int i = 1; i < rowIndex; ++i) {
            temp = temp * (rowIndex - i) / i;
            res.push_back(int(temp));
        }

        return res;
    }
};
```