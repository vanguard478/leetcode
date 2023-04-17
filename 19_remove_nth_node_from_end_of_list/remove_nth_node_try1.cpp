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
  ListNode *removeNthFromEnd(ListNode *head, int n) {

    ListNode *temp_ptr = new ListNode();
    temp_ptr->next=head;

    /*
    This is incorrect solution as the slow and fast ptr are refering directly 
    to the head and not through the temp_ptr
    Beacause of this error, the final modification is not reflected in the 
    temp_ptr when slow_ptr->next update is made to delete the nth node from 
    end by setting it to slow_ptr->next->next. 
    Consider the case of just two nodes n1 and n2 ,with n=2 (element to be 
    removed. In this case the slow_ptr doesnt move away from the head, and stays 
    there as n=2 (delay =2) and so the incorrect update is made, where 
    slow_ptr->next is updated to null ptr. and the first element which should 
    have been deleted stays there.
    */
    ListNode *slow_ptr = head; // Changing this to temp_ptr will make it work
    ListNode *fast_ptr = head; // Changing this to temp_ptr will make it work
    int delay = 0;

    while (fast_ptr != nullptr && fast_ptr->next != nullptr) {
      fast_ptr = fast_ptr->next;
      if(delay>=n){
        slow_ptr= slow_ptr->next;
      }
      delay++;
    }
  
    slow_ptr->next=slow_ptr->next->next;
    return temp_ptr->next;
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