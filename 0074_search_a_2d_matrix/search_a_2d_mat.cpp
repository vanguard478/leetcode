#include <iostream>
#include <vector>
using namespace std;
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row_lowerb = 0, row_upperb = rows - 1;
        int row_mid ;

        while (row_lowerb <= row_upperb) {
            row_mid = row_lowerb + (row_upperb - row_lowerb) / 2;
            int val = matrix[row_mid][0];
            if (target == val) {
                return true;
            } else if (target < val) {
                row_upperb = row_mid - 1;
            } else {
                row_lowerb = row_mid + 1;
            }

        }

        return false;
    }
};

// Main driver function for search in a sorted 2d matrix

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 21 ;
    Solution sol;
    bool res = sol.searchMatrix(matrix, target);
    cout << "The result is " << res << endl;
    return 0;
}