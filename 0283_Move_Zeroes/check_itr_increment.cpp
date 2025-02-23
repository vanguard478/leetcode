#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    auto itr_zero = nums.begin();
    auto itr = itr_zero;

    cout << "Before incrementing itr_zero: " << *itr_zero << " " << *itr << endl;

    ++itr_zero;

    cout << "After incrementing itr_zero: " << *itr_zero << " " << *itr << endl;

    return 0;
}