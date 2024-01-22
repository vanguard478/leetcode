#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    int binarySearchInRow(vector<int>& row, int target) {
        int low = 0, high = row.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (target == row[mid]) {
                return mid;
            } else if (target > row[mid]) {
                low = mid + 1;
            }
            // else if (target < row[mid]){
            else {
                high = mid - 1;
            }
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        int row_lowerb = 0, row_upperb = rows - 1;
        int row_mid;

        while (row_lowerb <= row_upperb) {
            row_mid = row_lowerb + (row_upperb - row_lowerb) / 2;
            if (target > matrix[row_mid].back()) {
                row_lowerb = row_mid + 1;
            } else if (target < matrix[row_mid].front()) {
                row_upperb = row_mid - 1;
            } else {
                return binarySearchInRow(matrix[row_mid], target) != -1;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5},
        {6, 7, 9},
        {12, 13, 14}};

    int target = 12;
    Solution sol;
    bool isInMatrix = sol.searchMatrix(matrix, target);

    if (isInMatrix) {
        std::cout << "Possible row index for the element: " << std::endl;
    } else {
        std::cout << "Element does not belong in any row." << std::endl;
    }

    return 0;
}