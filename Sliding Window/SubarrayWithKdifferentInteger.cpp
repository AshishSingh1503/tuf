#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution {
public:
    int subarraysWithEqualorLess(vector<int>& nums, int k) {
        if (k < 0) return 0;

        unordered_map<int, int> freq;
        int i = 0;
        int count = 0;

        for (int j = 0; j < nums.size(); j++) {
            freq[nums[j]]++;

            while (freq.size() > k) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0)
                    freq.erase(nums[i]);
                i++;
            }

            count += (j - i + 1);
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithEqualorLess(nums, k) -
               subarraysWithEqualorLess(nums, k - 1);
    }
};
