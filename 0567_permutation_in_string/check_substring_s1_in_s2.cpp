/**
 * @file 567. Permutation in String
 * @brief In this approach we are keeping two pointers on the left and right. 
 * @date 2023-04-19
 * 
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
   public:
    unordered_map<char, int> get_frequency(const string& s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        return freq;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_freq = get_frequency(s1);                             // O(n)
        unordered_map<char, int> window_freq = get_frequency(s2.substr(0, s1.length()));  // O(n)

        for (size_t i = 0; i < s2.length() - s1.length(); ++i) {  // O(m - n)
            if (s1_freq == window_freq) {
                return true;
            }
            // Update window_freq by removing s2[i] and adding s2[i + s1.length()]
            window_freq[s2[i]]--;
            if (window_freq[s2[i]] == 0) {
                window_freq.erase(s2[i]);
            }
            /*
            This i+s1.length() together with the for loop condition 
            s2.length() - s1.length() will ensure that we are moving across 
            all the elements in s2. 
            */
            window_freq[s2[i + s1.length()]]++;
        }

        if (s1_freq == window_freq) {  // Check last window
            return true;
        }

        return false;
    }
};

//testing code
int main() {
    Solution s;
    string s1 = "acb";
    string s2 = "eidcbaooo";
    cout << std::boolalpha << s.checkInclusion(s1, s2) << endl;
    return 0;
}