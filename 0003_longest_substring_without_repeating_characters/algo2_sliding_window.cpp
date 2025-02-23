#include "../utils/draw_ptr_for_str.h"
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string str) {
    int l = 0, r = 0, result = 0;
    std::unordered_map<char, int> char_map;
    for (int r = 0; r < str.length(); r++) {
      std::cout << "***Entry**\n";
      draw_pointers(str, l, r);
      char right = str[r];
      if (char_map.count(right)) {

        /**
         * @brief if we encounter a repeating character we update the starting
         * index left to the  position right after the previous occurrence of
         * the character. This is ensured by the max operation and as the value
         * stored in the map is index+1 for each character, which gets updated
         * as the right pointer moves across the array.
         *
         */
        l = max(l, char_map[right]);
        std::cout << "***Mid****\n";
        draw_pointers(str, l, r);
      }

      result = max(result, r - l + 1);
      char_map[right] = r + 1;
    }
    return result;
  }
};

// testing code for main function
int main() {
  Solution s;
  string str = "abcabcbb";
  cout << s.lengthOfLongestSubstring(str) << endl;
  return 0;
}