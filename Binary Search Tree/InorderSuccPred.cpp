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

class solution{
public:
    pair<int,int> PredeccorSuccessor(TreeNode* root,  int key){
        TreeNode* temp=root;
        int pred=-1;
        int succ=-1;
        while(temp->val!=key){
            if(temp->val>key){
                succ=temp->val;
                temp=temp->left;
            }
            else{
                pred=temp->val;
                temp=temp->right;
            }
        }

        TreeNode* leftTree=temp->left;
        while(leftTree!=NULL){
            pred=leftTree->val;
            leftTree=leftTree->right;
        }

        TreeNode* rightTree=temp->right;
        while(rightTree!=NULL){
            succ=rightTree->val;
            rightTree=rightTree->left;
        }

        pair<int,int> ans=make_pair(pred,succ);
        return ans;
    }

};