#include <bits/stdc++.h> 
#include<set>
void createAdjList(vector<pair<int,int>> edges,unordered_map<int,set<int>> &adj){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;

        adj[u].insert(v);
        adj[v].insert(u);
    }
}

void bfs(int node,unordered_map<int,set<int>> adj,unordered_map<int,bool> &visited,vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node]=true;

    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adj[front]){
            if(visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    //step1: create an adjacency list
    unordered_map<int,set<int>> adj;
    createAdjList(edges,adj);

    //make a visited map
    unordered_map<int,bool> visited;

    //mark all the nodes as false
    for(int i=0;i<vertex;i++){
        visited[i]=false;
    }
    //make a result vector to store the order
    vector<int> ans;
    //traverse all the nodes
    for(int i=0;i<vertex;i++){
        if(visited[i]==false){
            bfs(i,adj,visited,ans);
        }
    }
    return ans;
}
