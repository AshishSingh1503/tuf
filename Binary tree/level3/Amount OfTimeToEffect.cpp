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
    //parent mapping plus returning starting point
    TreeNode* markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &ParentMap, int start){
        TreeNode* result=NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->val==start){
                result=curr;
            }
            if(curr->left){
                ParentMap[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                ParentMap[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return result;
    }

    void InfectedTime(TreeNode* node,unordered_map<TreeNode*,TreeNode*> &ParentMap, int &ans) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(node);
        visited[node]=true;
        while(!q.empty()){
            bool flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    flag=1;
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    flag=1;
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(ParentMap[current] && !visited[ParentMap[current]]){
                    flag=1;
                    q.push(ParentMap[current]);
                    visited[ParentMap[current]]=true;
                }
            }
            if(flag==1){
                ans++;
            }
        }    
    }

    int amountOfTime(TreeNode* root, int start) {

        unordered_map<TreeNode*,TreeNode*> ParentMap;
        TreeNode* startNode=markParents(root,ParentMap,start);
        int ans=0;
        InfectedTime(startNode,ParentMap,ans);
        return ans;
   
    }
};