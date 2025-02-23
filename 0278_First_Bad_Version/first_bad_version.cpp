#include <iostream>
using namespace std;

// function to return an array of bools to represent the versions of the software given the
// number of versions n.The first bad version is the first true in the array of bools and all subsequent versions are bad
bool* versions;

bool* getVersions(int n) {
    bool* versions = new bool[n];
    for (int i = 0; i < n; i++) {
        versions[i] = false;
    }
    // generate a random number between 1 and n
    srand(time(NULL));
    auto a = rand();
    int badVersion = rand() % n + 1;
    cout << " First Bad version is: " << badVersion << endl;
    versions[badVersion] = true;

    // Fill the rest of the array with true
    for (int i = badVersion + 1; i < n; i++) {
        versions[i] = true;
    }
    return versions;
}

// API isBadVersion
bool isBadVersion(int index) {
    return versions[index];
}

class Solution {
   public:
    int firstBadVersion(int n) {
        int low = 1, high = n, mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (isBadVersion(mid)) {
                //We need the high to be set to mid and not mid+1 as we need
                //to find the first bad version. If we set high to mid+1, we
                // might ignore the first bad version, if it is the mid.
                high = mid;
                std::cout << "\nIn if block: The values of low : " << low << " and high : " << high << endl;
            } else {
                low = mid + 1;
                std::cout << "\nThe values of low : " << low << " and high : " << high << endl;
            }
        }
        return low;
    }
};

// main code for testing
int main() {
    int n = 23;
    versions = getVersions(n);
    // print versions array
    for (int i = 0; i < n; i++) {
        cout << versions[i] << " ";
    }
    std::cout << endl;
    // Find the first bad version
    Solution s;
    cout << "First bad version using serach is: " << s.firstBadVersion(n) << endl;

    delete[] versions;
    return 0;
}