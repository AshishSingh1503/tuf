#include <iostream>
using namespace std;
#include <stack>

class MinStack {
private:
    stack<int> st;
    stack<int> minst;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty() || val<=minst.top()){
            minst.push(val);
        }
        
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        int val=st.top();
        st.pop();
        if(minst.top()==val){
            minst.pop();
        }
        
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top();
    }
    
    int getMin() {
        if(minst.empty()) return -1;
        return minst.top();
        
    }
};
