#include<stdio.h>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        pq.push({0,0});
        //({time,node})

        vector<long long> tm(n,LLONG_MAX);
        tm[0]=0;

        vector<int> ways(n,0);
        ways[0]=1;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long time=it.first;
            int node=it.second;
            for(auto i : adj[node]){
                if(time+i.second<tm[i.first]){
                    tm[i.first]=time+i.second;
                    pq.push({time+i.second,i.first});
                    ways[i.first]=ways[node];
                }
                else if(time+i.second==tm[i.first]){
                    ways[i.first]=(ways[i.first]+ways[node])% MOD;
                }
            }
        }
        return ways[n-1];
        
    }
};