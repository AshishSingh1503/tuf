#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int> last(256, -1);

        int maxlen=0;
        int l=0;
        int r=0;

        while(r<n) {
            if (last[s[r]] >= l) {
                l = last[s[r]] + 1;
            }

            last[s[r]] = r;
            int len = r - l + 1;
            maxlen = max(maxlen, len);
            r++;
        }

        return maxlen;
    }
};
