**Binary Search in a 2D Matrix**

**Key Concepts:**

1. **Binary Search:** An efficient algorithm for finding an item in a sorted sequence, dividing the search interval in half each time.
2. **2D Matrix with Sorted Rows:** Matrix where each row is sorted in ascending order.
3. **Ordered Rows:** Each row starts with an element greater than the last element of the previous row.

---

**Notes:**

**1. Understanding the Matrix Structure:**

- **Sorted Rows:** Each row of the matrix is sorted in non-decreasing order. This allows binary search within individual rows.
- **Ordered Rows:** The first element of each row is greater than the last element of the previous row, allowing us to treat the matrix as a partially sorted structure.

**2. Two-Level Binary Search Approach:**

- **First Level (Row Identification):** Identify which row could potentially contain the target element.
- **Second Level (Element Search):** Once the row is identified, perform a standard binary search within that row to find the target element.

**3. Row Identification Logic:**

- Compare the target with the first and last elements of the middle row.
- If the target is greater than the last element, the target must be in a higher row, so the row_lowerb is incremented above the calculated middle row .
- If the target is less than the first element, the target must be in an lower row, so the row_upperb is decremented below the calculated middle row.
- If the target falls between the first and last elements, this is the potential row, and we can perform the row specific binary search for this row.

**4. Element Search Logic:**

- Perform standard binary search in the identified row.
- This is effective due to the sorted nature of the rows.

**5. Code Implementation:**

- **Function `bool isElementInMatrix(vector<vector<int>>& matrix, int target)`**
  - Identify the correct row using binary search.
  - Search for the element within the row using another binary search.

**Example Code:**

```cpp
bool binarySearchInRow(const vector<int>& row, int target) {
    int left = 0, right = row.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (row[mid] == target) return true;
        else if (row[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return false;
}

bool isElementInMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int low = 0, high = matrix.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (target < matrix[mid].front()) high = mid - 1;
        else if (target > matrix[mid].back()) low = mid + 1;
        else return binarySearchInRow(matrix[mid], target);
    }
    return false;
}
// Code for finding the row index instead of just checking the presence of the elelement. 
int findRowIndex(vector<vector<int>>& matrix, int target) {
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
            return binarySearchInRow(matrix[row_mid], target) != -1 ? row_mid : -1;
        }
    }
    return -1;
}
```

**6. Complexity Analysis:**

- **Time Complexity:** O(log(m) + log(n)), where m is the number of rows and n is the number of columns. This is due to binary search in both row selection and element search.
- **Space Complexity:** O(1), as no extra space is used apart from variables for iteration and comparison.

---

**Summary:**
The approach utilizes the strengths of binary search in two dimensions, leveraging the sorted nature of each row and the ordered arrangement of the rows themselves. This method is highly efficient for large matrices where a linear search would be impractical. Understanding these principles and their implementation is crucial for algorithms involving sorted and partially sorted data structures.