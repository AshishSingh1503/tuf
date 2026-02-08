#include<stdio.h>
using namespace std;
#include<vector>

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>> dp(n,vector<unsigned long long>(amount+1,0));

        for(int am=0;am<=amount;am++){
            dp[0][am]=(am%coins[0]==0);
        }

        for(int ind=1;ind<n;ind++){
            for(int am=0;am<=amount;am++){
                unsigned long long notTake=dp[ind-1][am];
                unsigned long long take=0;
                if(am>=coins[ind]){
                    take=dp[ind][am-coins[ind]];
                }

                dp[ind][am]=notTake+take;
                
            }
        }

        return dp[n-1][amount];
        
    }
};