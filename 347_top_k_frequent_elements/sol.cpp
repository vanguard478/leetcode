#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Create a freuqncy map
        std::unordered_map<int, int> freq_map;
        for (auto i : nums) {
            freq_map[i]++;
        }

        auto comparator = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        };
        std::priority_queue<pair<int, int>, vector<pair<int, int>>,decltype(comparator)> pq(comparator);

        // Since we are poping the top element to keep only TOP k elements in the
        // priority queue, we need to put elements in PQ such that the smallest
        // element is at the top. Hence, we use a min heap and the comparator
        // function should reutrn a.second > b.second i.e. a will have a smaller
        // priority than b if freq of a is greater than freq of b.
        for (auto& entry : freq_map) {
            pq.emplace(entry);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        //print the priority queue
        // while (!pq.empty()) {
        //     cout << pq.top().first << " -> " << pq.top().second << endl;
        //     pq.pop();
        // }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }

};

int main() {
    Solution sol;
    vector<int> nums = {0,0,0,0,0,0,1, 1, 1,2,3, 2, 2,3,3,3,3,3,3, 3};
    int k = 3;
    vector<int> res = sol.topKFrequent(nums, k);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}