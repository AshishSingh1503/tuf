#include <iostream>
using namespace std;
#include <vector>
#include <stack>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};