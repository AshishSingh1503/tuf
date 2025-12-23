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

    TreeNode* solve(vector<int>& postorder,vector<int>& inorder,int &postOrderIndex,int inOrderStart,int inOrderEnd,map<int,int> &nodeToIndex){
        // base case
        if (postOrderIndex < 0 || inOrderStart > inOrderEnd) {
            return NULL;
        }

        int element = postorder[postOrderIndex--];
        TreeNode* root = new TreeNode(element);

        int position = nodeToIndex[element];

        root->right = solve(postorder, inorder,postOrderIndex,position + 1,inOrderEnd,nodeToIndex);
        root->left = solve(postorder, inorder,postOrderIndex,inOrderStart,position - 1,nodeToIndex);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postOrderIndex = postorder.size()-1;
        map<int,int> nodeToIndex;

        createMapping(inorder, nodeToIndex);

        TreeNode* root = solve(postorder, inorder,postOrderIndex,0,inorder.size() - 1,nodeToIndex);

        return root;
    }
};