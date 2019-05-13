#include <vector>
#include <string>
#include <queue>
using namespace std;

// DFS回溯法
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty()) {
            return false;
        }
        
        if (word.empty()) {
            return true;
        }

        int rowSize = board.size();
        int colSize = board[0].size();

        queue<pair<int, int> > indexs;
        // 找出与 word[0] 相同的字符的索引
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (board[i][j] == word[0]) {
                    indexs.push(make_pair(i, j));
                }
            }
        }

        while (!indexs.empty()) {
            vector<vector<bool> > isVisited(rowSize, vector<bool>(colSize, false));
            bool isExist = exist(board, indexs.front(), word, 0, isVisited);
            if (isExist) {
                return true;
            }
            indexs.pop();
        }
        
        return false;
    }

private:
    bool exist(vector<vector<char> > &board, pair<int, int> indexs,
               string &word, int index, vector<vector<bool> > &isVisited) {
        int row = indexs.first;
        int col = indexs.second;
        int rowSize = board.size();
        int colSize = board[0].size();

        // 搜索结束
        if (index >= word.size()) {
            return true;
        }

        // 超出二维数组范围
        if (row < 0 || row >= rowSize || col < 0 || col >= colSize) {
            return false;
        }

        // 访问过 或者 字符不相同
        if (isVisited[row][col] || board[row][col] != word[index]) {
            return false;
        }

        // 未访问过且字符相同
        isVisited[row][col] = true;
        bool left = exist(board, make_pair(row - 1, col), word, index + 1, isVisited);
        if (left) {
            return true;
        }

        bool right = exist(board, make_pair(row + 1, col), word, index + 1, isVisited);
        if (right) {
            return true;
        }
        
        bool top = exist(board, make_pair(row, col - 1), word, index + 1, isVisited);
        if (top) {
            return true;
        }
        
        bool bottom = exist(board, make_pair(row, col + 1), word, index + 1, isVisited);
        if (bottom) {
            return true;
        }
        // 回溯
        isVisited[row][col] = false;
        
        return false;
    }
};