
/**
 * Given the head of a linked list and two integers m and n. Traverse the linked list and remove some nodes in the following way:

    Start with the head as the current node.
    Keep the first m nodes starting with the current node.
    Remove the next n nodes
    Keep repeating steps 2 and 3 until you reach the end of the list.

Return the head of the modified list after removing the mentioned nodes
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode* tmp_ptr = new ListNode();
        tmp_ptr->next = head;
        ListNode* m_ptr = tmp_ptr;
        ListNode* prev = new ListNode();
        int save_m, del_n;
        while (m_ptr != nullptr && m_ptr->next != nullptr) {
            save_m = 0;
            del_n = 0;
            while (save_m < m && m_ptr->next != nullptr) {
                m_ptr = m_ptr->next;
                save_m++;
            }
            prev = m_ptr;

            while (del_n < n && m_ptr->next != nullptr) {
                m_ptr = m_ptr->next;
                del_n++;
            }
            prev->next = m_ptr->next;
        }
        return tmp_ptr->next;
    }
};


// testing code in the main function
int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
    ListNode* node5 = new ListNode(6);
    ListNode* node6 = new ListNode(7);
    ListNode* node7 = new ListNode(8);
    ListNode* node8 = new ListNode(9);
    ListNode* node9 = new ListNode(10);
    ListNode* node10 = new ListNode(11);
    ListNode* node11 = new ListNode(12);
    ListNode* node12 = new ListNode(13);
    ListNode* node13 = new ListNode(14);
    ListNode* node14 = new ListNode(15);
    ListNode* node15 = new ListNode(16);
    ListNode* node16 = new ListNode(17);
    ListNode* node17 = new ListNode(18);
    ListNode* node18 = new ListNode(19);
    ListNode* node19 = new ListNode(20);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    node10->next = node11;
    node11->next = node12;
    node12->next = node13;
    node13->next = node14;
    node14->next = node15;
    node15->next = node16;
    node16->next = node17;
    node17->next = node18;
    node18->next = node19;
    // Initial list: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

    ListNode* res = sol.deleteNodes(head, 3, 2);
    // Final list: 1 2 3 6 7 8 11 12 13 16 17 18
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}