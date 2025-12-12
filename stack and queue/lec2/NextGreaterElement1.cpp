#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <unordered_map>
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> ans(n2, -1); 
        stack<int> s;

        for (int i = n2 - 1; i >= 0; i--) {
            int curr = nums2[i];
            while (!s.empty() && s.top() <= curr) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] = s.top();
            }
            s.push(curr);
        }

        unordered_map<int,int> m;
        for (int i = 0; i < n2; i++) {
            m[nums2[i]] = ans[i];
        }

        vector<int> result;
        for (int x : nums1) {
            result.push_back(m[x]);
        }

        return result;
    }
};