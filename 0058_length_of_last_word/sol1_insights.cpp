#include <iostream>
#include <string>
using namespace std;

class Solution
{
  
  public: 
  inline int lengthOfLastWord(std::basic_string<char> s)
  {
    if(s.empty()) {
      return 0;
    } 
    
    int i = static_cast<int>(s.length() - 1);
    int last_idx = 0;
    int first_idx = 0;
    while((i >= 0) && !static_cast<bool>(isalpha(static_cast<int>(s.operator[](i))))) {
      --i;
    }
    
    last_idx = i;
    while((i >= 0) && !static_cast<bool>(isspace(static_cast<int>(s.operator[](i))))) {
      --i;
    }
    
    first_idx = i;
    return (last_idx - first_idx) + (first_idx != -1 ? 1 : 0);
  }
  
  // inline constexpr Solution() noexcept = default;
};



int main()
{
  std::basic_string<char> input = std::basic_string<char>{"   fly me   to   the moon  ", std::allocator<char>()};
  Solution sol;
  int result = sol.lengthOfLastWord(std::basic_string<char>(input));
  std::operator<<(std::cout, "Length of last word: ").operator<<(result).operator<<(std::endl);
  return 0;
}

