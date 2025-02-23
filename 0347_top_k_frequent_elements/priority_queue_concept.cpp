#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    unordered_map<int, int> frequency_map = {{1, 13}, {2, 15}, {3, 12}, {4, 11}, {5, 14}};

    auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> max_heap(compare);

    for (const auto& entry : frequency_map) {
        max_heap.push(entry);
    }

    while (!max_heap.empty()) {
        cout << max_heap.top().first << " -> " << max_heap.top().second << endl;
        max_heap.pop();
    }

    return 0;
}
