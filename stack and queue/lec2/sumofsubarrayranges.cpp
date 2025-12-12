#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> psee(n), nse(n);
        stack<int> st;

        while (!st.empty()){
            st.pop();
        }

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            } 
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()){
            st.pop();
        } 

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sumMin = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            sumMin += (long long)nums[i] * left * right;
        }

        vector<int> plee(n), nle(n);

        while (!st.empty()){
            st.pop();
        } 

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            plee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()){
            st.pop();
        } 
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nle[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long sumMax = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - plee[i];
            long long right = nle[i] - i;
            sumMax += (long long)nums[i] * left * right;
        }

        return sumMax - sumMin;
    }
};
