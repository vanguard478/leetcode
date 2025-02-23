Binary search is an efficient algorithm for finding an item from a sorted list of items. It works by repeatedly dividing in half the portion of the list that could contain the item, until you've narrowed down the possible locations to just one.

### Basic Concept of Binary Search

1. **Initial Setup**: You start with three variables: `low`, `high`, and `mid`. `low` is set to the first index of the array (usually 0), and `high` is set to the last index (length of the array - 1).

2. **Finding the Middle**: In each iteration, you calculate the middle index `mid` by taking the average of `low` and `high` (`(low + high) / 2`).

3. **Comparison**: Compare the element at the `mid` index with the target element. If they are equal, you've found the target and can return the `mid` index.

4. **Adjusting the Search Range**:
    - If the target is less than the element at `mid`, you need to search in the left half of the array, so you set `high` to `mid - 1`.
    - If the target is greater than the element at `mid`, you need to search in the right half, so you set `low` to `mid + 1`.

5. **Repeat or Conclude**: Repeat the above steps until `low` is greater than `high`, indicating the element is not in the array, or until you find the target.

### C++ Implementation of Binary Search

```cpp
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Avoids overflow

        if (arr[mid] == target) {
            return mid;  // Target found
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;  // Target not found
}

int main() {
    std::vector<int> arr = {2, 3, 4, 10, 40};
    int target = 10;
    int result = binarySearch(arr, target);

    if (result != -1) {
        std::cout << "Element is found at index " << result << std::endl;
    } else {
        std::cout << "Element is not present in array" << std::endl;
    }

    return 0;
}
```

### Issue with using `size_t` for Indexing in Binary Search

In C++, `size_t` is an unsigned integral type. When you use `size_t` for indexing in binary search, it can cause issues, especially when calculating `mid` and adjusting the `high` index.

- **Underflow Issue**: When `low` is 0 and `high` is also 0 (i.e., you're searching in an empty range or the first element), `high - 1` will underflow. Since `size_t` is unsigned, `high - 1` will wrap around to become a very large number instead of -1, leading to incorrect behavior or even infinite loops.

This issue does not occur with signed integers like `int`, as they correctly handle negative values. For binary search, it's generally safer to use signed integers for indexing to avoid these kinds of underflow issues.