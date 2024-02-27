#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }

        int i = s.length() - 1;
        int last_idx = 0, first_idx = 0;
        while ((i >= 0) && !isalpha(s[i])) {
            --i;
        }
        last_idx = i;
        while ((i >= 0) && !isspace(s[i])) {
            --i;
        }
        first_idx = i;
        return last_idx - first_idx + (first_idx != -1 ? 1 : 0);
    }
};

int main() {
    std::string input{ "   fly me   to   the moon  " };
    Solution sol;

    int result = sol.lengthOfLastWord(input);
    std::cout << "Length of last word: " << result << std::endl;

    return 0;
}
