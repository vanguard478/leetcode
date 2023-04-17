#include<iostream>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy_ptr = new ListNode();
        dummy_ptr->next = head;
        ListNode* reverse_ptr = dummy_ptr;
        ListNode* front_ptr = dummy_ptr;
        int delay = 0;
        while(reverse_ptr!= nullptr && reverse_ptr->next != nullptr){
            reverse_ptr = front_ptr->next;
            if(delay>=k){
                front_ptr=front_ptr->next;
            }
        }
        
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
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    ListNode *temp_ptr = sol.swapNodes(head,2);
    while(temp_ptr!=nullptr){
        cout<<temp_ptr->val<<" ";
        temp_ptr=temp_ptr->next;
    }
    cout<<endl;
    return 0;
}

