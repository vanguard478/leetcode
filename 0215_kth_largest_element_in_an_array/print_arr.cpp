#include <iostream>

template <size_t N>
void printArray(int (&arr)[N], int low, int high) {
    std::cout << "The current array with low " << low << " and high " << high << " is: ";
    for (int i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};

    printArray(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);

    return 0;
}