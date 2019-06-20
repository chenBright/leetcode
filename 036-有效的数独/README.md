# 036-有效的数独

## 题目

leetcode：[036-有效的数独](https://leetcode-cn.com/problems/valid-sudoku/)


## 哈希表

使用哈希表记录数字`1~9`出现过的位置（行、列），`key`为数字`1~9`，`value`为一个内部类`Item`的`vector`，用于表示行列，并重载了`operation==()`运算，判断两个位置是否在同一列、同一行或者同一个`3x3`宫格中。

遍历二维数组：

- 如果哈希表中没有此数字，则新建一个项，并将该数字对应的`Item`加到`vector`中。
- 如果哈希表哄存在此数字，则使用`std::find`查找有没有跟该数字位于在同一列、同一行或者同一个`3x3`宫格中。

判断两个位置是否在同一个宫内的方法有两种：

- `item1.row / 3 == item2.row / 3 && item1.col / 3 == item2.col / 3`
- `(row / 3) * 3 + columns / 3`，官方计算宫格索引号的方法，如下图。

![宫格索引](/Users/chenbright/Desktop/c:c++_workspace/leetcode/036-有效的数独/img.png)

```c++
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int row = board.size();
        int col = board[0].size();

        unordered_map<int, vector<Item> > m;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }

                int num = board[i][j] - '0';
                Item *tmpItem = new Item(i, j);
                if (m.count(num)) {
                    if (find(m[num].begin(), m[num].end(), *tmpItem) != m[num].end()) {
                        return false;
                    } else {
                        m[num].push_back(*tmpItem);
                    }
                } else {
                    m[num] = vector<Item>(1, *tmpItem);
                }
            }
        }

        return true;
    }

private:
    class Item {
    public:
        Item(int row, int col) : row_(row), col_(col) {

        }

        // 判断两个位置是否在同一列、同一行或者同一个3x3宫格中
        bool operator==(const Item &rhs) const {
            return this->row_ == rhs.row_ || this->col_ == rhs.col_ ||
                   (this->row_ / 3 == rhs.row_ / 3 && this->col_ / 3 == rhs.col_ / 3);
        }

    private:
        int row_;
        int col_;
    };
};
```

