#include <iostream>
#include <string>
using namespace std;
class Solution {
   public:
    bool compareArray(const int* arr1, const int* arr2) {
        for (int i = 0; i < 26; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string& s1, string& s2) {
        int str1[26] = {}, str2[26] = {};
        int s1_len = s1.length(), s2_len = s2.length();
        for (int i = 0; i < s1_len; ++i) {
            str1[s1[i] - 'a']++;
            str2[s2[i] - 'a']++;
        }

        for (int i = 0; i < s2_len - s1_len; ++i) {
            if (compareArray(str1, str2)) {
                return true;
            }
            str2[s2[i] - 'a']--;
            str2[s2[i + s1_len] - 'a']++;
        }

        return compareArray(str1, str2);
    }
};

//testing code
int main() {
    Solution s;
    string s1 = "abco";
    string s2 = "eidcbaooo";
    cout << std::boolalpha << s.checkInclusion(s1, s2) << endl;
    return 0;
}