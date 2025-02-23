#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using StringVector = std::vector<std::string>;
using AnagramMap = std::unordered_map<std::string, StringVector>;
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<StringVector> result;
        AnagramMap words_map;
        for (auto word : strs) {
            auto key_curr = getKey(word);
            auto itr = words_map.find(key_curr);
            if (itr != words_map.end()) {
                itr->second.push_back(word);
            } else {
                words_map.emplace(key_curr, std::vector<std::string>{word});
            }
        }
        for (const auto& kv : words_map) {
            result.push_back(kv.second);
        }
        return result;
    }
    std::string getKey(std::string str) {
        std::string result;
        int char_arr[26] = {};
        for (auto i : str) {
            char_arr[i - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            result += std::to_string(char_arr[i]);
        }
        return result;
    }
};

//testing code main ["bdddddddddd","bbbbbbbbbbc"]
int main() {
    Solution sol;
    vector<string> strs = {"bdddddddddd","bbbbbbbbbbc"};
    vector<vector<string>> result = sol.groupAnagrams(strs);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}