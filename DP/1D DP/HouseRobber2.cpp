#include<stdio.h>
using namespace std;
#include<vector>

class Solution {
private:
    int rob1(vector<int> &arr){
        int n=arr.size();
        int prev=arr[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=arr[i]+prev2;
            int notTake=prev;
            int curi=max(take,notTake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
    
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
        }
        
        return max(rob1(temp1),rob1(temp2));
    }
};