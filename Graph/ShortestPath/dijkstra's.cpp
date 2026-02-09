#include<stdio.h>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>

class Solution{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, S});

        while (!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int weight = it[1];

                if (dis + weight < dist[adjNode]) {
                    dist[adjNode] = dis + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
    
};