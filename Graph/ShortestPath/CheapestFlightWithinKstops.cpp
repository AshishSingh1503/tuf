#include<stdio.h>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int,list<pair<int,int>>> adj;
        for(int i=0;i<flights.size();i++){
            int from=flights[i][0];
            int to=flights[i][1];
            int price=flights[i][2];

            adj[from].push_back(make_pair(to,price));

        }
        
        vector<int> price(n,INT_MAX);
        
        queue<pair<int,pair<int,int>>> q;
        //({stops,{node,price}})
        q.push({0,{src,0}});
  
        price[src]=0;
       
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k){
                continue;
            }

            for(auto i : adj[node]){
                if(price[i.first]>cost+i.second && stops<=k){
                    price[i.first]=cost+i.second;
                    q.push({stops+1,{i.first,cost+i.second}});
                }
            }

        }

        if(price[dst]==INT_MAX){
            return -1;
        }
        else{
            return price[dst];
        }

    }
};