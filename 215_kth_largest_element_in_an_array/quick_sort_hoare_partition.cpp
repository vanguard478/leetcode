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
    std::cout << "The array at the start is ***** \n";
    for (int i = 0; i < len; i++) {
        std::cout << std::setw(2) << nums[i] << " " << std::flush;
    }
    std::cout << std::endl;
    //print the position of left, pivot and right in the next line;
    for (int i = 0; i < len; i++) {
        if (i == low) {
            std::cout << " L ";
        } else if (i == high) {
            std::cout << " R ";
            // } else if (i == pivot) {
            //     std::cout << " P ";
        } else {
            std::cout << " " << i << " ";
        }
    }
    std::cout << std::endl;

    while (true) {
        while (nums[++i] < pivot) {
        };
        std::cout << "The current value of i is " << i << "\n";

        while (nums[--j] > pivot) {
            if (j == low) {
                break;
            }
        }
        std::cout << "The current value of j is " << j << "\n";
        if (i >= j) {
            std::cout << " Breaking swap loop  with i " << i << " and j " << j << "\n";
            break;
        }
        std::cout << "Swapping element idx " << i << " and " << j << "\n";
        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[high]);
    std::cout << "Swapping pivot element idx " << i << " and " << high << "\n";

    std::cout << "The array at the end is ***** \n";
    for (int k = 0; k < len; k++) {
        std::cout << std::setw(2) << nums[k] << " ";
    }
    std::cout << std::endl;
    //print the position of left, pivot and right in the next line;
    for (int k = 0; k < len; k++) {
        if (k == low) {
            std::cout << " L ";

        } else if (k == high && k == i) {
            std::cout << " B ";
        } else if (k == high) {
            std::cout << " R ";
        } else if (k == i) {
            std::cout << " P ";
        } else {
            std::cout << " " << k << " ";
        }
    }
    std::cout << std::endl;
    std::cout<<"The returned pivot index is "<<i<<"\n";
    return i;
}
void quickSort(int arr[], int len, int low, int high) {
    std::cout<<"Entering quick sort with low "<<low<<" and high "<<high<<"\n";
    if (low < high) {
        int pivotIndex = parititon(arr, len, low, high);
        std::cout << "Operating on The current pivot index  " << pivotIndex << "\n";
        quickSort(arr, len, low, pivotIndex - 1);
        quickSort(arr, len, pivotIndex + 1, high);
    }
    else{
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
