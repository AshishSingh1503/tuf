#include<iostream>
using namespace  std;
#include<vector>

class Solution {
public:

    int numsSubarrayWithSumEqualOrLess(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int sum=0;
        int count=0;
        if(k<0){
            return 0;
        }
        while(r < nums.size()){
            sum+=(nums[r]%2);
            while(sum>k){
                sum=sum-(nums[l]%2);
                l++;
            }
            count = count + (r-l+1);
            r++;
        }
        return count;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        //similar approach as of Binary Subarray with sum
        //odd->1
        //even->0

        return (numsSubarrayWithSumEqualOrLess(nums,k) - numsSubarrayWithSumEqualOrLess(nums,k-1));
    
    }
};