#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;

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
