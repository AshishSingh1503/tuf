#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=0, rightmax=0, total=0, l=0, r=height.size()-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(leftmax>height[l]){
                    total+=leftmax-height[l];
                }
                else{
                    leftmax=height[l];
                }
                l++;
            }
            else{
                if(rightmax>height[r]){
                    total+=rightmax-height[r];
                }
                else{
                    rightmax=height[r];
                }
                r--;
            }
        } 
        return total;
        
    }
};