#include <iomanip>
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int len, int low, int high) {
    std::cout << "The current array with low " << low << " and high " << high << " is: ";
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int hoarePartition(int arr[], int len, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    std::cout << "The array at the start is ***** \n";
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    //print the position of left, pivot and right in the next line;
    for (int i = 0; i < len; i++) {
        if (i == low) {
            std::cout << "L ";
        } else if (i == high) {
            std::cout << "R ";
        } else if (i == pivot) {
            std::cout << "P ";
        } else {
            std::cout << " - ";
        }
    }
    std::cout << std::endl;

    while (true) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i >= j) {
        std:
            cout << "The array at the end is with pivot " << pivot << " ";
            printArray(arr, len, low, high);
            return j;
        }
        swap(arr[i], arr[j]);
    }
}
int parititon(int nums[], int len, int low, int high) {
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
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[high]);

    return i;
}
void quickSort(int arr[], int len, int low, int high) {
    std::cout << "Entering quick sort with low " << low << " and high " << high << "\n";
    if (low < high) {
        int pivotIndex = parititon(arr, len, low, high);
        std::cout << "Operating on The current pivot index  " << pivotIndex << "\n";
        quickSort(arr, len, low, pivotIndex - 1);
        quickSort(arr, len, pivotIndex + 1, high);
    } else {
        std::cout << "Rejecting The current low and high are " << low << " and " << high << "\n";
    }
}

int main() {
    int arr[] = {10, 7, 10, 7, 8, 9, 1, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, n, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
