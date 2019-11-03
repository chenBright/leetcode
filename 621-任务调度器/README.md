# 621-任务调度器

## 题目

leetcode：[621-任务调度器](https://leetcode-cn.com/problems/task-scheduler/)

## 排序

参考[LeetCode官方题解 方法一](https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode/)。

规定`n + 1`个任务为一轮，每次先安排出现次数多的任务。

时间复杂度：***O(time)***，由于我们给每个任务都安排了时间，因此时间复杂度和最终的答案成正比。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> m(26, 0);
        for (const auto& c : tasks) {
            ++m[c - 'A'];
        }

        sort(m.begin(), m.end());
        int time = 0;
        while (m[25] > 0) {
            int i = 0;
            while (i <= n) {
                if (m[25] == 0) {
                    break;
                }
                if (i < 26 && m[25 - i] > 0) {
                    --m[25 - i];
                }
                ++time;
                ++i;
            }
            sort(m.begin(), m.end());
        }

        return time;
    }
};
```

## 优先队列

参考[LeetCode官方题解 方法二](https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode/)。

使用优先队列自动排序的特性。

时间复杂度：***O(time)***，由于我们给每个任务都安排了时间，因此时间复杂度和最终的答案成正比。

空间复杂度：***O(1)***。

```c++
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> m(26, 0);
        for (const auto& c : tasks) {
            ++m[c - 'A'];
        }

        priority_queue<int> q; // 大根堆
        for (const auto& n : m) {
            if (n > 0) {
                q.push(n);
            }
        }

        int time = 0;
        while (!q.empty()) {
            int i = 0;
            vector<int> tmp;
            while (i <= n) {
                if (!q.empty()) {
                    if (q.top() > 1) {
                        tmp.push_back(q.top() - 1);
                    }
                    q.pop();
                }
                ++time;
                if (q.empty() && tmp.empty()) {
                    break;
                }
                ++i;
            }
            for (const auto& t : tmp) {
                q.push(t);
            }
        }

        return time;
    }
};
```

## 其他

参考[LeetCode官方题解 方法三](https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode/)和[博客](https://github.com/grandyang/leetcode/issues/621)。