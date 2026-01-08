#include<iostream>
using namespace  std;
#include<vector>

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26,0);
        int l=0;
        int r=0;
        int maxfreq=0;
        int maxlen=0;
        while(r<s.size()){
            arr[s[r]-'A']++;
            maxfreq=max(maxfreq,arr[s[r]-'A']);
            if((r-l+1)-maxfreq>k){
                arr[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxfreq<=k){
                maxlen=max(maxlen,r-l+1);
            }
            r++;
        }

        return maxlen;
        
    }
};