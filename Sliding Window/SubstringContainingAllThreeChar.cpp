#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0;
        int r=0;
        vector<int> lastseen(3,-1);
        int count=0;
        while(r<s.size()){
            lastseen[s[r]-'a']=r;

            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1){
                count = count + (min(lastseen[0],min(lastseen[1],lastseen[2])) + 1);
            }
            r++;
        }
        return count;
        
    }
};