#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
 
using namespace std;

class Solution {
   public:
    string longestCommonPrefix(vector<string> &strs) {
        std::unordered_map<std::string, int> word_map;
        for (int word_idx{0}; word_idx < strs.size() ; ++word_idx) {
            string word{strs[word_idx]};
            for (int i = 1; i <= word.size(); ++i) {
                auto sub_string = word.substr(0, i);
                if (word_idx > 0 && word_map.find(sub_string) == word_map.end()) {
                    return "";
                } else {
                    word_map[sub_string]++;
                }
            }
        }
        std::string longest_prefix;
        int min_length{0};
        for (auto &pair : word_map) {
            if (pair.second > min_length) {
                min_length = pair.second;
                longest_prefix = pair.first;
            }
        }

        return longest_prefix;
    }
};

int main() {
    // Test your code here
    Solution solution;

    // vector<string> strs = {"a"};
    // string result = solution.longestCommonPrefix(strs);
    // cout << "Longest common prefix: " << result << endl;

    vector<string> strs3 = {"a", "ab", "ac"};
    string result3 = solution.longestCommonPrefix(strs3);
    cout << "Longest common prefix: " << result3 << endl;
    // Example test case
    vector<string> strs1 = {"flower", "flow", "flight"};
    string result1 = solution.longestCommonPrefix(strs1);
    cout << "Longest common prefix: " << result1 << endl;

    // Additional test cases
    vector<string> strs2 = {"dog", "racecar", "car"};
    string result2 = solution.longestCommonPrefix(strs2);
    cout << "Longest common prefix: " << result2 << endl;

    return 0;
}
