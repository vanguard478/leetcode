#include <iostream>
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
  ListNode *swapNodes(ListNode *head, int k) {
    ListNode *dummy_ptr = new ListNode();
    dummy_ptr->next = head;
    bool front_flag = false;
    ListNode *fast_ptr = dummy_ptr;
    ListNode *slow_ptr = dummy_ptr;
    ListNode *front_ele_ptr = new ListNode();
    int delay = 1;
    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
      fast_ptr = fast_ptr->next;
      if (delay == k) {
        front_ele_ptr = fast_ptr;
        slow_ptr = slow_ptr->next;
      }
      if (delay > k) {
        slow_ptr = slow_ptr->next;
      }
      delay++;
    }
    int temp = front_ele_ptr->val;
    front_ele_ptr->val = slow_ptr->val;
    slow_ptr->val = temp;
    return dummy_ptr->next;
  }
};

// testing code in the main function
int main() {
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode *node3 = new ListNode(4);
  ListNode *node4 = new ListNode(5);
  ListNode *node5 = new ListNode(6);
  ListNode *node6 = new ListNode(7);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  node4->next = node5;
  node5->next = node6;
  // Initial linked list values:
  // 1 2 3 4 5 6 7

  ListNode *temp_ptr = sol.swapNodes(head, 3);
  // Values after swapping:
  // 1 2 5 4 3 6 7
  while (temp_ptr != nullptr) {
    cout << temp_ptr->val << " ";
    temp_ptr = temp_ptr->next;
  }
  cout << endl;
  return 0;
}
