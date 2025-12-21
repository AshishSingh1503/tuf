#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<unordered_map>

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
    void markParents(TreeNode* root,unordered_map<TreeNode* , TreeNode*> &ParentMap){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                ParentMap[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                ParentMap[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* , TreeNode*> ParentMap;
        markParents(root,ParentMap);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=true;
        int distance=0;
        while(!q.empty()){
            if(distance==k){
                break;
            }
            distance++;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(ParentMap[current] && !visited[ParentMap[current]]){
                    q.push(ParentMap[current]);
                    visited[ParentMap[current]]=true;
                }
            }

        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* current=q.front();
            q.pop();
            result.push_back(current->val);
        }
        return result;   
    }
};