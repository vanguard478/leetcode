#include<iostream>
using namespace std;
//Find first bad version
bool isBadVersion(int version) ;
class Solution {
   public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        int mid = low + (high - low) / 2;
        while (low <= high) {
            //since we iteratively want to find smallest bad version
            // we arent returning mid here if it is bad, but rather 
            //go to the left side of the array.
            if (isBadVersion(mid)) {
                high = mid - 1;
            } else
                low = mid + 1;
            mid = low + (high - low) / 2;
        }
        return low;
    }
};
bool isBadVersion(int version) {
    if (version >= 4)
        return true;
    else
        return false;
}

int main() {
    Solution sol_obj = Solution();
    int n = 5;
    int result = sol_obj.firstBadVersion(n);
    cout << "First bad version is " << result << "\n";
    return 0;
}
