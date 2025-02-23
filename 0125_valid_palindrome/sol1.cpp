#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    bool isPalindrome(string str) {
        int i = 0, j = str.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(str[i])) {
                i++;
            }
            while (i < j && !isalnum(str[j])) {
                j--;
            }
            if (i < j && tolower(str[i++]) != tolower(str[j--]) ){
                return false;
            }
        }
        return true;
    }
};

// testing code for isPalindrome
int main() {
    Solution sol;
    std::string check = "A man, a plan, a canal: Panama";
    std::cout << std::boolalpha << sol.isPalindrome(check) << std::endl;
    return 0;
}