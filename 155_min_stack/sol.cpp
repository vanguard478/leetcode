#include<iostream>
struct Node{
    int m_value;
    int m_min_value;
    Node* m_next;
    Node(int value,int min_value,Node* node):m_value(value), m_min_value(min_value),m_next(node){

    }
    private:
        int top;

};
class MinStack {
public:
    Node* topNode = nullptr;
    MinStack() {
    }
    
    void push(int val) {
        if(!topNode || val<= topNode->m_min_value) {
            topNode = new Node(val,val,topNode);
        }
        else {
            topNode = new Node(val,topNode->m_min_value,topNode);
        }
    }
    
    void pop() {
        auto old_ptr = topNode;
        topNode = topNode->m_next;
        delete old_ptr;
    }
    
    int top() {
        return topNode->m_value;
    }
    
    int getMin() {
        return topNode->m_min_value;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// Main code for 155_min_stack problem
int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    std::cout << obj->getMin() << std::endl;
    obj->pop();
    std::cout << obj->top() << std::endl;
    std::cout << obj->getMin() << std::endl;
    return 0;
}