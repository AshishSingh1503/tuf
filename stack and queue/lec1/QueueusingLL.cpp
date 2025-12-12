#include <iostream>
using namespace std;
#include <queue>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
private:
    Node* head; // front
    Node* tail; // rear

public:
    Queue() {
        head = NULL;
        tail = NULL;
    }

    // Enqueue (push) – insert at end
    void push(int x) {
        Node* newNode = new Node(x);

        if (tail == NULL) { 
            // queue is empty
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    // Dequeue (pop) – remove from front
    int pop() {
        if (head == NULL) {
            return -1; // queue empty
        }

        int val = head->data;
        Node* temp = head;
        head = head->next;

        // If queue becomes empty, reset tail also
        if (head == NULL) {
            tail = NULL;
        }

        delete temp;
        return val;
    }

    // Peek front
    int front() {
        if (head == NULL) return -1;
        return head->data;
    }

    // Check if empty
    bool empty() {
        return head == NULL;
    }
};
