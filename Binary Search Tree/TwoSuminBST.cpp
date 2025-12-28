#include<iostream>
using namespace std;
#include<vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &inordervec){
        if(root==NULL){
            return;
        }
        inorder(root->left,inordervec);
        inordervec.push_back(root->val);
        inorder(root->right,inordervec);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inordervec;
        inorder(root,inordervec);
        int i=0;
        int j=inordervec.size()-1;
        while(i<j){
            int sum=inordervec[i]+inordervec[j];
            if(sum==k){
                return true;
            }
            else if(sum>k){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }
};