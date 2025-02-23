#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int,int> index_map;
        int vec_size= nums.size();
        for(int i=0;i<vec_size;++i){
            if(index_map.find(nums[i])!=index_map.end()){
                /**
                 * @brief It may happen that the last seen element index
                 * is not nearby, then this wont return and subsequently before
                 * the end of the for loop, the index will be updated with the 
                 * latest index.
                 * 
                 */
                if(abs(index_map[nums[i]]-i)<=k){
                    return true;
                }
            }
            index_map[nums[i]]=i;
        }
        return false;
    }
};

//testing code
int main() {
    Solution sol;
    vector<int> nums = {1,0,1,1};
    cout << std::boolalpha << sol.containsNearbyDuplicate(nums, 1) << endl;
    return 0;
}