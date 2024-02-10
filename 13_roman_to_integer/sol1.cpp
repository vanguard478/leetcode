#include <iostream>
using namespace std;
#include <unordered_map>

class Solution {
   public:
    static inline std::unordered_map<std::string, int> valueMap = {
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900}};

    int getNumericValue(char letter) {
        switch (letter) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return -1;
        }
    }
    static int getValue(const std::string& key) {
        auto it = valueMap.find(key);
        if (it != valueMap.end()) {
            return it->second;
        } else {
            return -1;
        }
    }

    int romanToInt(string s) {
        int cur = s.length() - 1;
        int sum = 0;

        while (cur >= 0) {
            int pre_cur = cur - 1;

            if (pre_cur >= 0 && (s[pre_cur] == 'I' || s[pre_cur] == 'X' || s[pre_cur] == 'C')) {
                std::string key = std::string(1, s[pre_cur]) + s[cur];
                int value = getValue(key);

                if (value != -1) {
                    sum += value;
                    cur -= 2;
                } else {
                    sum += getNumericValue(s[cur]);
                    --cur;
                }

            } else {
                sum += getNumericValue(s[cur]);
                --cur;
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    string romanNumeral = "MCMXCIV";  // Example input
    int result = solution.romanToInt(romanNumeral);
    cout << "The integer representation of " << romanNumeral << " is: " << result << endl;
    return 0;
}
