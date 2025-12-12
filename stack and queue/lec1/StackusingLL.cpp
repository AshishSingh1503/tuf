#include <iostream>
using namespace std;
#include <stack>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
private:
    Node* topNode; // pointer to top of stack

public:
    Stack() {
        topNode = NULL;
    }

    // Push element on top
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
    }

    // Pop top element
    int pop() {
        if (topNode == NULL) {
            return -1; // or throw error
        }

        int val = topNode->data;
        Node* temp = topNode;
        topNode = topNode->next;

        delete temp;
        return val;
    }

    // Get top element
    int top() {
        if (topNode == NULL) {
            return -1;
        }
        return topNode->data;
    }

    // Check if stack is empty
    bool empty() {
        return topNode == NULL;
    }
};
