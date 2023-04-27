#include <iostream>
#include <vector>

#include <unordered_map>

using namespace std;
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int cnt = 9;
        std::unordered_map<int, bool> row_map[cnt];  // 0-8
        std::unordered_map<int, bool> col_map[cnt];  // 0-8
        std::unordered_map<int, bool> box_map[cnt];  // 0-8
        int row_idx, col_idx, box_idx;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                row_idx = i / 3;
                col_idx = j / 3;
                box_idx = row_idx * 3 + col_idx;
                int element = board[i][j] - '0';
                if (row_map[i][element] || col_map[j][element] || box_map[box_idx][element]) {
                    return false;
                } else {
                    row_map[i][element] = true;
                    col_map[j][element] = true;
                    box_map[box_idx][element] = true;
                }
            }
        }
        return true;
    }
};

//testing code for 36_valid_sudoku.cpp
int main() {
    Solution sol;
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    bool res = sol.isValidSudoku(board);
    cout << res << endl;
    return 0;
}