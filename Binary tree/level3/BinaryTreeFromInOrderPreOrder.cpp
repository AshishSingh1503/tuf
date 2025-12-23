#include<iostream>
using namespace std;
#include<vector>
#include<map>

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
    void createMapping(vector<int>& inorder, map<int,int> &nodeToIndex) {
        for (int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int &preOrderIndex,int inOrderStart,int inOrderEnd,map<int,int> &nodeToIndex){
        // base case
        if (preOrderIndex >= preorder.size() || inOrderStart > inOrderEnd) {
            return NULL;
        }

        int element = preorder[preOrderIndex++];
        TreeNode* root = new TreeNode(element);

        int position = nodeToIndex[element];

        root->left = solve(preorder, inorder,preOrderIndex,inOrderStart,position - 1,nodeToIndex);
        root->right = solve(preorder, inorder,preOrderIndex,position + 1,inOrderEnd,nodeToIndex);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        map<int,int> nodeToIndex;

        createMapping(inorder, nodeToIndex);

        TreeNode* root = solve(preorder, inorder,preOrderIndex,0,inorder.size() - 1,nodeToIndex);

        return root;
    }
};