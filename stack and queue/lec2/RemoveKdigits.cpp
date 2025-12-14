#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <list>
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        list<char> result;
        while (!st.empty()) {
            result.push_front(st.top());  
            st.pop();
        }

    
        while (!result.empty() && result.front() == '0') {
            result.pop_front();
        }

    
        if (result.empty()){
            return "0";
        } 

        
        string ans(result.begin(), result.end());
        return ans;
    }
};
