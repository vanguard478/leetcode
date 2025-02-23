#include<vector>
#include<string>
#include<iostream>
#include<stack>
#include <unordered_map>  
#include <functional>     
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stk;
        std::unordered_map<std::string,std::function<int(int,int)>> operators {
            {"+",[](int a,int b){return a+b;}},
            {"-",[](int a,int b){return a-b;}},
            {"*",[](int a ,int b) {return a*b;}},
            {"/",[](int a ,int b){return a/b;}}
            };
        for (auto i: tokens){
            if (operators.find(i)==operators.end()){
                //ab
                stk.push(std::stoi(i));
            }
            else if (operators.find(i)!=operators.end() && !stk.empty() && stk.size()>=2)
            {
                //ab+
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(operators[i](a,b));
            }
            

        }
        return stk.top();

    }
};

// Main code for 150 evaluating reverse polish

int main(){
    Solution sol;
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    int ans = sol.evalRPN(tokens);
    std::cout<<"The answer is: "<<ans<<"\n";
    return 0;

}