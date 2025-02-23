#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
   public:
    unordered_map<char, int> get_freq_map(std::string str) {
        std::unordered_map<char, int> freq_map;
        for (auto i : str) {
            /**
             * @brief Although we can check for the element availability, 
             * if the element is not present in the map, it will be initialized
             * with a default value of 0 (for int) and we can directly
             * increment it to 1;
             * 
             */
            // if(freq_map.find(i)!=freq_map.end()){
            //     freq_map[i]=1;
            // }
            // else{
            //     freq_map[i]++;
            // }
            freq_map[i]++;
        }
        return freq_map;
    }
    bool checkInclusion(string str1, string str2) {
        int s1_len= str1.length(),s2_len=str2.length();
        auto s1_map= get_freq_map(str1);
        auto window_map= get_freq_map(str2.substr(0,s1_len));

        for(int i=0;i<s2_len-s1_len;i++){
            char c = str2[i];
            if(s1_map==window_map){
                return true;
            } 
            window_map[c]--;
            if(window_map[c]==0){
                window_map.erase(c);
            }
            window_map[str2[i+s1_len]]++;
        }
        if(s1_map==window_map){
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