#include<bits/stdc++.h>
void dfs(int node,int par,unordered_map<int,vector<int>> &adj,
unordered_map<int,bool> &visited,vector<int> &disc,vector<int> &low,
int &timer,
vector<vector<int>> &result){
    visited[node]=true;
    // parent[node]=par;
    disc[node]=timer;
    low[node]=timer++;
    
    for(auto nbr:adj[node]){
        if(nbr==par){
            continue;
        }
        if(!visited[nbr]){
            dfs(nbr,node,adj,visited,disc,low,timer,result);
            low[node]=min(low[nbr],low[node]);
            if(low[nbr]>disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            low[node]=min(disc[nbr],low[node]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // vector<int> parent(v,-1);
    int parent=-1;
    unordered_map<int,bool> visited;
    vector<int> disc(v,-1);
    vector<int> low(v,-1);
    int timer=0;
    vector<vector<int>> result;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,parent,adj,visited,disc,low,timer,result);
        }
    }
    return result;
}
