#include<stdio.h>
using namespace std;
#include<vector>

class Solution {
public:
    //count partiotion with given difference
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
        }
        if(totalsum<target){
            return 0;
        }

        if((totalsum - target) % 2 != 0) return 0;
        int sum=(totalsum-target)/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,0));

        //base case
        if(nums[0] == 0){
            dp[0][0] = 2;   // +0 and -0
        } 
        else {
            dp[0][0] = 1;   // not take
            if(nums[0] <= sum)
                dp[0][nums[0]] = 1;
        }

        for(int index=1;index<n;index++){
            for(int s=0;s<=sum;s++){
                int notTake=dp[index-1][s];
                int take=0;
                if(nums[index]<=s){
                    take =dp[index-1][s-nums[index]];
                }
                dp[index][s]=take+notTake;

            }
        }

        return dp[n-1][sum];   
    }
};