// headers for cpp
#include <cmath>
#include <iostream>
#include <string>
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
  ListNode *middleNode(ListNode *head) {
    ListNode *slow_ptr = head;
    ListNode *fast_ptr = head;
    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
      slow_ptr = slow_ptr->next;
      fast_ptr = fast_ptr->next;
    }
    return slow_ptr;
  }
};

// main code for testing
int main() {
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode *second = new ListNode(2);
  ListNode *third = new ListNode(3);
  ListNode *fourth = new ListNode(4);
  ListNode *fifth = new ListNode(5);
  ListNode *sixth = new ListNode(6);

  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;
  sixth->next = nullptr;
  ListNode *result = sol.middleNode(head);
  // cout << result->val << endl;
  return 0;
}