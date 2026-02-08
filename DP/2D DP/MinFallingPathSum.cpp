#include<stdio.h>
using namespace std;
#include<vector>

class Solution{
public:
    int minFallingSum(vector<vector<int>> &matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int u=matrix[i][j]+dp[i-1][j];
                int ld=INT_MAX;
                int rd=INT_MAX;
                if(j-1>=0) ld=matrix[i][j]+dp[i-1][j-1];
                if(j+1<m) rd=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(u,min(ld,rd));
            }
        }
        int mini=dp[n-1][0];
        for(int j=1;j<m;j++){
            mini=min(dp[n-1][j],mini);
        }

        return mini;
    }
};