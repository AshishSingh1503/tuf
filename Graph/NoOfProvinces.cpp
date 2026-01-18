#include<stdio.h>
using namespace std;
#include<vector>
#include<unordered_map>
#include<list>

class Solution {
public:
    void dfs(int node, unordered_map<int, list<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto i : adj[node]) {
            if (!vis[i]) {
                dfs(i, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int row = isConnected.size();
        int col = isConnected[0].size();

        unordered_map<int, list<int>> adj;

        // build adjacency list
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (isConnected[i][j] == 1 && i != j) {  
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(row, 0);
        int count = 0;

        // count connected components
        for (int i = 0; i < row; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adj, vis);
            }
        }

        return count;
    }
};
