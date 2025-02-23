#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        std::string encoded;
        for (auto word : strs) {
            encoded += std::to_string(word.length()) + "#" + word;
        }
        return encoded;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        int i = 0, j = 0, word_len;
        std::vector<string> decoded;
        std::string word;
        int str_size = str.length();
        while (i < str_size) {
            j = i;
            while (str[j] != '#') {
                j++;
            }
            word_len = str[i] - '0';
            word = str.substr(j + 1, word_len);
            decoded.push_back(word);
            i = j + word_len + 1;
        }
        return decoded;
    }
};

//testing code for 271_encode_and_decode_strings.cpp
int main() {
    Solution sol;
    vector<string> strs = {"lint", "code", "love", "you"};
    string res = sol.encode(strs);
    std::cout << "The encoded strings are :\n";

    cout << res << endl;
    //decode the strings
    vector<string> decoded = sol.decode(res);
    std::cout << "The decoded strings are :\n";
    for (auto i : decoded) {
        std::cout << i << " ";
    }
    std::cout << endl;
    return 0;
}