#include<iostream>
using namespace std;

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
    bool isBST(TreeNode* root, long long minVal, long long maxVal) {
        if (root == NULL){
            return true;
        } 

        if (root->val <= minVal || root->val >= maxVal){
            return false;
        }
        
        bool left=isBST(root->left, minVal, root->val);
        bool right=isBST(root->right, root->val, maxVal);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }
};