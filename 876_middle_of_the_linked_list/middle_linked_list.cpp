// headers for cpp
#include <iostream>
#include <string>
#include <vector>
#include<cmath>
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
    int i = 0;
    ListNode *temp = new ListNode();
    temp = head;
    while (temp != nullptr && temp->next != nullptr) {
      ++i;
      temp = temp->next;
    }
    int target = ceil(i/2.0);
    std::cout<<"Middle node is "<<target<< " with number of node"<<i<<std::endl;
    i = 0;
    temp = head;
    while (i < target) {
      temp= temp->next;
      i++;
    }
    return temp;
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