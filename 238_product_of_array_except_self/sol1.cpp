#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix=1,postfix=1;

        vector<int> result(nums.size());
        for(int i=0;i<nums.size();++i){
            result[i] = prefix;
            prefix=prefix*nums[i];
        }
        for(int i=nums.size()-1;i>-1;--i){
            result[i]=postfix*result[i];
            postfix=postfix*nums[i];
        }
    return result;
    }
};


//testing code for 238_product_of_array_except_self.cpp
int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    vector<int> res = sol.productExceptSelf(nums);
    for(auto i: res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}