#### What is the idea behind the compartor funciton in the priority_queue. I am confused whether to return smaller or greater than true

The idea behind the comparator function in the `priority_queue` is to define a custom order or priority for the elements in the queue. <u>***The comparator function takes two elements as input and returns `true` if the first element should have a lower priority (come after) the second element in the queue, and `false` otherwise.***</u>

In C++, the `priority_queue` is implemented as a max-heap by default, meaning the element with the highest priority is at the top. To achieve this behavior, the comparator function should return `true` when the first element has a lower priority than the second element.

1. If you want to create a max-heap (highest priority elements at the top), the comparator function should return `true` when the first element is smaller than the second element:

`auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {     return a.second < b.second; };`

2. If you want to create a min-heap (lowest priority elements at the top), the comparator function should return `true` when the first element is greater than the second element:

`auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {     return a.second > b.second; };`



**Remember, the `priority_queue` will put elements in order based on the comparison result from the comparator function. If the comparator function returns `true`, it means the first element should have a lower priority (come after) the second element in the queue.**

```cpp
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

int main() {
    unordered_map<int, int> frequency_map = {{1, 3}, {2, 5}, {3, 2}, {4, 1}, {5, 4}};

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

```
