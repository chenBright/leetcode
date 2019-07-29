# 224-基本计算器

## 题目

leetcode：[224-基本计算器](https://leetcode-cn.com/problems/basic-calculator/)

## 实现1

参考[博客 解法一](https://www.cnblogs.com/grandyang/p/4570699.html)。

```c++
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int len = s.size();
        int op = 1; // 1 表示加号，-1 表示减号
        stack<int> nums;

        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                int num = 0;
                while (i < len && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                result += op * num;
                --i; // 每次循环会将 i 递增，所以此处要将 i减 1
            } else if (s[i] == '+') {
                op = 1;
            } else if (s[i] == '-') {
                op = -1;
            } else if (s[i] == '(') {
                nums.push(result);
                nums.push(op);
                result = 0;
                op = 1;
            } else if (s[i] == ')') {
                op = nums.top();
                nums.pop();
                result = result * op + nums.top();
                nums.pop();
            }
            // 跳过空格
        }

        return result;
    }
};
```

## 实现2

实现2是实现1的递归版本。

基本思想：***遍历到左括号，则递归计算括号内的式子，直到遍历到右括号***。

```c++
class Solution {
public:
    int calculate(string s) {
        index = 0;
        str = s;
        return calculate();
    }
private:
    int index; // 索引值
    string str;
    
    int calculate() {
        int result = 0;
        int len = str.size();
        int op = 1; // 1 表示加号，-1 表示减号

        for (; index < len; ++index) {
            if (str[index] >= '0' && str[index] <= '9') {
                int num = 0;
                while (index < len && str[index] >= '0' && str[index] <= '9') {
                    num = num * 10 + (str[index] - '0');
                    ++index;
                }
                result += op * num;
                --index; // 每次循环会将 i 递增，所以此处要将 i减 1
            } else if (str[index] == '+') {
                op = 1;
            } else if (str[index] == '-') {
                op = -1;
            } else if (str[index] == '(') {
                ++index; // 从括号内的字符开始遍历
                result += op * calculate();
            } else if (str[index] == ')') {
                return result;
            }
            // 跳过空格
        }

        return result;
    }
};
```

## 实现3

参考[博客 解法二](https://www.cnblogs.com/grandyang/p/4570699.html)。

```c++
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int len = s.size();
        int op = 1; // 1 表示加号，-1 表示减号
        stack<int> nums;
        int num = 0;

        for (int i = 0; i < len; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+' || s[i] == '-') {
                result += op * num;
                num = 0;
                op = s[i] == '-' ? -1 : 1;
            } else if (s[i] == '(') {
                // 将括号前面计算的结果压入栈中保存
                nums.push(result);
                nums.push(op);
                result = 0;
                op = 1;
            } else if (s[i] == ')') {
                result += op * num; // 加上括号内的最后一个数字
                num = 0;

                // 将括号前面计算的结果压入栈中保存
                op = nums.top();
                nums.pop();
                result = result * op + nums.top();
                nums.pop();
            }
            // 跳过空格
        }

        return result + op * num; // 最后一个数字在循环中没计算
    }
};
```

## 实现4

实现4是实现3的递归版本。

基本思想：***遍历到左括号，则递归计算括号内的式子，直到遍历到右括号***。

```c++
class Solution {
public:
    int calculate(string s) {
        index = 0;
        str = s;
        return calculate();
    }
private:
    int index;
    string str;

    int calculate() {
        int result = 0;
        int len = str.size();
        int op = 1; // 1 表示加号，-1 表示减号
        int num = 0;

        for (; index < len; ++index) {
            if (str[index] >= '0' && str[index] <= '9') {
                num = num * 10 + (str[index] - '0');
            } else if (str[index] == '+' || str[index] == '-') {
                result += op * num;
                num = 0;
                op = str[index] == '-' ? -1 : 1;
            } else if (str[index] == '(') {
                ++index; // 从括号内的字符开始遍历
                result += op * calculate();
            } else if (str[index] == ')') {
                result += op * num;
                return result;
            }
            // 跳过空格
        }

        return result + op * num; // 最后一个数字在循环中没计算
    }
};
```

