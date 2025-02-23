#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        auto start=s.begin();
        auto end=prev(s.end());

        while(start<=end){
            char temp=*start;
            *start=*end;
            *end=temp;
            start++;
            end--;
        }
    }
};


//main function to test the code
int main(){
    Solution sol;
    vector<char> s = {'e','a','c','l','o'};
    sol.reverseString(s);
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
    return 0;
}