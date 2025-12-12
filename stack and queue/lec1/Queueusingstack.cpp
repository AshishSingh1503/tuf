#include <iostream>
using namespace std;
#include <queue>
#include <stack>

class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {}

    void push(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push new element into empty s1
        s1.push(x);

        // Move everything back to s1 so that top of s1 is the front of queue
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) return -1;
        int val = s1.top();
        s1.pop();
        return val;
    }

    int peek() {
        if (s1.empty()) return -1;
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};