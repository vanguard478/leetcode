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

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy_ptr = new ListNode();
        dummy_ptr->next = head;
        ListNode *slow_ptr = dummy_ptr;
        ListNode *fast_ptr = dummy_ptr;
        for (int i = 0; i < n; ++i)
            fast_ptr = fast_ptr->next;

        while (fast_ptr != nullptr && fast_ptr->next != nullptr)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
        ListNode *tmp_ptr = slow_ptr->next;
        slow_ptr->next = slow_ptr->next->next;
        delete (tmp_ptr);

        return dummy_ptr->next;
    }
};

// testing code in the main function
int main() {
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode *node1 = new ListNode(2);
//   ListNode *node2 = new ListNode(3);
//   ListNode *node3 = new ListNode(4);
//   ListNode *node4 = new ListNode(5);
  head->next = node1;
//   node1->next = node2;
//   node2->next = node3;
//   node3->next = node4;
  ListNode *res = sol.removeNthFromEnd(head, 2);
  while (res) {
    cout << res->val << " ";
    res = res->next;
  }
  cout << endl;
  return 0;
}