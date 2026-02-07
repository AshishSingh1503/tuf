#include<stdio.h>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution {
public:
    bool checkcycle(int node,vector<int> &visited,
    vector<int> &dfsvisited,vector<vector<int>> &adj){
        visited[node]=true;
        dfsvisited[node]=true;
        for(auto it:adj[node]){
            if(!visited[it]){
                if(checkcycle(it,visited,dfsvisited,adj)){
                    return true;
                }
            }
            else if(dfsvisited[it]){
                return true;
            }
        }
        dfsvisited[node]=false;
        return  false;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[v].push_back(u);
        }

        vector<int> visited(numCourses, 0);
        vector<int> dfsvisited(numCourses, 0);
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                bool cyclefound=checkcycle(i,visited,dfsvisited,adj);
                if(cyclefound){
                    return false;
                }
            }
        }
        return true;  
    }
};