#include<stdio.h>
using namespace std;
#include<vector>
#include<unordered_map>
#include<queue>

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int, pair<int,int>>,vector<pair<int, 
        pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;

        dist[0][0]=0;
        pq.push({0,{0,0}});
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int effort=it.first;
            int row=it.second.first;
            int col=it.second.second;

            if(row==n-1 && col==m-1){
                return effort;
            }

            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort=max(abs(heights[row][col] - heights[nrow][ncol]),effort);
                    if(newEffort<dist[nrow][ncol]){
                        dist[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});
                    }
                }
            }

        }

        return 0;
        
    }
};