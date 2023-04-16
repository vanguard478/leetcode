#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteMiddle(ListNode *head) {
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;
    ListNode *last_ptr;

    if(fast_ptr== nullptr || fast_ptr->next ==nullptr){
        return nullptr;
    }
    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
      last_ptr = slow_ptr;
      slow_ptr = slow_ptr->next;
      fast_ptr = fast_ptr->next->next;
    }

    if (last_ptr != nullptr) {
      last_ptr->next = slow_ptr->next;
    }
    return head;
  }
};

// main code for testing
int main() {
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode *node3 = new ListNode(4);
  ListNode *node4 = new ListNode(5);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  ListNode *res = sol.deleteMiddle(head);
  while (res) {
    cout << res->val << " ";
    res = res->next;
  }
  cout << endl;
  return 0;
}