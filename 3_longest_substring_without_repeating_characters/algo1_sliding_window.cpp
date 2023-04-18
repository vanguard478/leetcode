#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int l=0,r=0,result=0;
        std::unordered_map<char,int> char_map;
        while(r<str.length()){  
            char right = str[r];
            char_map[right]++;
            
            while(char_map[right]>1){
                char left = str[l];
                char_map[left]--;
                l++;
            }

            result=max(result,r-l+1);
            r++;
        }
        return result;
    }
};


//testing code for main function
int main()
{
    Solution s;
    string str = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}