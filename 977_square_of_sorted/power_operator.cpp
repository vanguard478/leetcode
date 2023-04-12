#include <iostream>
#include <chrono>
#include <cmath>

int main() {
    double a = 123.456;
    int n = 1000000;

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        double result = a * a;
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time_diff = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Using operator: " << time_diff.count() << " microseconds\n";

    start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        double result = std::pow(a, 2);
    }
    end_time = std::chrono::high_resolution_clock::now();
    time_diff = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);

    std::cout << "Using pow(): " << time_diff.count() << " microseconds\n";

    return 0;
}
