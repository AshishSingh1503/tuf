#include<iostream>
using namespace  std;
#include<vector>

class Solution {
public:
    int numsSubarrayWithSumEqualOrLess(vector<int>& nums, int goal){
        int l=0;
        int r=0;
        int sum=0;
        int count=0;
        if(goal<0){
            return 0;
        }
        while(r < nums.size()){
            sum+=nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return (numsSubarrayWithSumEqualOrLess(nums,goal) - numsSubarrayWithSumEqualOrLess(nums,goal-1));
        
    }
};