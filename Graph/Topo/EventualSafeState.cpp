#include<stdio.h>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // reverse graph
        vector<vector<int>> rev(n);
        
        vector<int> indegree(n, 0);//this is outdegree of original graph
        
        for (int i = 0; i < n; i++) {
            indegree[i] = graph[i].size();
            for (int v : graph[i]) {
                rev[v].push_back(i);
            }
        }
        

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int it : rev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
