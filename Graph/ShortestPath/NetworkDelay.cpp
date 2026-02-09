#include<stdio.h>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];

            adj[u].push_back(make_pair(v,w));
        }
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int time=it.first;
            int node=it.second;
            
            if (time > dist[node]) continue;
            for(auto i : adj[node]){
                if(time+i.second<dist[i.first]){
                    dist[i.first]=time+i.second;
                    pq.push({dist[i.first],i.first});
                }
            }
        }

        int maxi=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX){
                return -1;    
            }
            maxi=max(maxi,dist[i]);
        }
        return maxi;
        
    }
};