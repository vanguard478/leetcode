#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
   public:
    bool isAnagram(string str, string test) {
        if (str.size() != test.size()) {
            return false;
        }
        std::unordered_set<char> set;
        for(auto i : str){
            set.insert(i);
        }
        for(auto i : test){
            if(set.find(i) == set.end()){
                return false;
            }
        }
        return true;
    }
};

//main code for testing
int main() {
    Solution s;
    string s1 = "bnagram";
    string s2 = "nagaram";
    cout <<std::boolalpha<< s.isAnagram(s1, s2) << endl;
    return 0;
}