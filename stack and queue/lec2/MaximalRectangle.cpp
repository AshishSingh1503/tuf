#include <iostream>
using namespace std;
#include <vector>
#include <stack>
class Solution {
public:
    int largesthistogram(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxarea=0;

        for(int i=0;i<n;i++){
            while(!st.empty() &&  heights[st.top()]>heights[i]){
                int element=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxarea=max(maxarea,heights[element]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=n;
            int element=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxarea=max(maxarea,heights[element]*(nse-pse-1));
        }

        return maxarea;
        
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> prefixsum(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '1') {
                    sum += 1;
                } else {
                    sum = 0;
                }
                prefixsum[i][j] = sum;  
            }
        }
        int maxarea=0;
        for(int i=0;i<n;i++){
            maxarea=max(maxarea,largesthistogram(prefixsum[i]));
        }
        return maxarea;
        
    }
};