#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "../utils/draw_ptr_for_str.h"
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> chars;

    int left = 0;
    int right = 0;

    int res = 0;
    while (right < s.length()) {
      char r = s[right];
      chars[r]++;
      std::cout << "**Entry** :\n";
      draw_pointers(s, left, right);
      /**
       * @brief In this case when a character is found which is repeated, 
       * we go through the whole subtring previous intial index i.e. l towards
       * the right index untill the current char right has a count = 1. Notice 
       * that in this process, other letters which were in the sub-string can
       * have the index reduced back to 0 as we are moving from left to right
       * over the substring.
       * 
       */
      while (chars[r] > 1) {
        char l = s[left];
        chars[l]--;
        left++;
        std::cout << "**mid**** :\n";

        draw_pointers(s, left, right);
      }

      res = max(res, right - left + 1);

      right++;
      std::cout << "**Exit*** :\n";
      draw_pointers(s, left, right);
    }

    return res;
  }
};

// main code for testing
int main() {
  Solution sol;
  string s = "abcabcbb";
  int result = sol.lengthOfLongestSubstring(s);
  cout << result << endl;
  return 0;
}