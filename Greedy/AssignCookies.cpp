#include<stdio.h>
using namespace std;
#include<vector>
#include<queue>

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int i=0;
        int j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(j<m){
            if(i < n && g[i] <= s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};