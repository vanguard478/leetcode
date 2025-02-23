#include <algorithm>
#include <iostream>

int partition(int nums[], int low, int high) {
    int i = low - 1, j = high, pivot = nums[high];
    while (true) {
        while (nums[++i] < pivot) {
        };

        while (nums[--j] > pivot) {
            if (j == low) {
                break;
            }
        }
        if (i >= j) {
            break;
        }
        std::swap(nums[i], nums[j]);
    }
    std::swap(nums[i], nums[high]);

    return i;
}

int quickSelect(int nums[], int low, int high, int k) {
    if (low == high) {
        return nums[low];
    }

    int pivotIndex = partition(nums, low, high);

    if (k == pivotIndex) {
        return nums[k];
    } else if (k < pivotIndex) {
        return quickSelect(nums, low, pivotIndex - 1, k);
    } else {
        return quickSelect(nums, pivotIndex + 1, high, k);
    }
}

int findKthLargest(int nums[], int size, int k) {
    return quickSelect(nums, 0, size - 1, size - k);
}

int main() {
    int arr[] = {3, 5, 2, 2, 2, 1, 1, 5, 6, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    std::cout << "The " << k << "th largest element is: " << findKthLargest(arr, n, k) << std::endl;

    return 0;
}
