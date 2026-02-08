#include<stdio.h>
using namespace std;
#include<vector>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount){
        int n=coins.size();
        vector<int> prev(amount+1,0);
        vector<int> cur(amount+1,0);

        for(int am=0;am<=amount;am++){
            if(am%coins[0]==0) prev[am]=am/coins[0];
            else prev[am]=1e9;
        }

        for(int ind=1;ind<n;ind++){
            for(int am=0;am<=amount;am++){
                int notTake=prev[am];
                int take=1e9;
                if(am>=coins[ind]){
                    take=1+cur[am-coins[ind]];
                }
                cur[am] = min(notTake, take);
            }
            prev=cur;
        }

        if(prev[amount]>=1e9){
            return -1;
        }
        return prev[amount];

    }
};