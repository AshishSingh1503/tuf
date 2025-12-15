#include <iostream>
using namespace std;
#include <stack>

class StockSpanner {
public:
    stack<pair<int,int>> st;   // {price, index}
    int index;

    StockSpanner() {
        index = -1;
        while (!st.empty()) st.pop();
    }
    
    int next(int price) {
        index++;

        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int ans = st.empty() ? (index + 1) : (index - st.top().second);

        st.push({price, index});
        return ans;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */