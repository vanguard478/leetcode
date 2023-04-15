#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
  bool is_vowel(char c) {
    static const std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    return vowels.find(tolower(c)) != vowels.end();
  }
  string reverseVowels(string s) {
    auto start = s.begin();
    auto end = prev(s.end());
    while (start <= end) {
      if (is_vowel(*start)) {
        if (is_vowel(*end)) {
          char temp = *start;
          *start = *end;
          *end = temp;
          start++;
          end--;
        } else {
          end--;
        }
      } else {
        start++;
      }
    }
    return s;
  }
  string reverseVowels_n1(string s) {
    auto start = s.begin();
    auto end = prev(s.end());
    while (start <= end) {
        while((start<=end) && !is_vowel(*start)){
            ++start;
        }
        while((start<=end) && !is_vowel(*end)){
            --end;
        } 
        if(start<=end){
            std::swap(*start,*end);
            ++start;
            --end;
        }
    }
    return s;
  }
};

// main function for testing the code
int main() {
  Solution sol;
  string s = "bea";
  cout << sol.reverseVowels_n1(s) << endl;
  return 0;
}