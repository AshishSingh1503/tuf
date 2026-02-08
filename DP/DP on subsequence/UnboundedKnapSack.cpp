#include<stdio.h>
using namespace std;
#include<vector>

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1,0));
        
        for(int w=0;w<=capacity;w++){
            dp[0][w]=(w/wt[0])*val[0];
        }
        for(int i=1;i<n;i++){
            for(int w=0;w<=capacity;w++){
                int notTake=dp[i-1][w];
                int take=0;
                if(wt[i]<=w){
                    take=val[i]+dp[i][w-wt[i]];
                }
                dp[i][w]=max(take,notTake);
            }
        }
        
        return dp[n-1][capacity];
    }
};