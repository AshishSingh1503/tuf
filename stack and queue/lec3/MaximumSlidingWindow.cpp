#include <iostream>
using namespace std;
#include <vector>
#include <deque>
#include <list>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> l;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                l.push_back(nums[dq.front()]);
            }
        }
        return vector<int>(l.begin(), l.end());
    }
};