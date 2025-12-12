#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const long long MOD = 1000000007LL;


        vector<int> psee(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()){
            st.pop();
        }

        vector<int> nse(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            } 
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];       
            long long right = nse[i] - i;        
            long long contrib = ( (arr[i] * (left % MOD)) % MOD * (right % MOD) ) % MOD;
            result = (result + contrib) % MOD;
        }

        return (int)result;
    }
};