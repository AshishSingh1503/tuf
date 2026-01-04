#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxIndex=0;
        for(int i=0;i<n;i++){ 
            if(maxIndex<i){
                return false;
            }
            int Index = i + nums[i];
            maxIndex=max(Index,maxIndex);
        }
        return true;
    }
};