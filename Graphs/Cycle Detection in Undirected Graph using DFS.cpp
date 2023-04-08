#include<unordered_map>
#include<list>
#include<queue>

void createAdjList(vector<vector<int>>&edges,int m,unordered_map<int,list<int>> &adj){
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
bool dfs(int src,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
    visited[src]=true;
    
    for(auto i:adj[src]){
        if(!visited[i]){
            bool detect=dfs(i,src,visited,adj);
            if(detect){
                return true;
            }
        }
        else if(visited[i] && i!=parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //step1: make an adj list
    unordered_map<int,list<int>> adj;
    createAdjList(edges,m,adj);

    //step2: make a visited list
    unordered_map<int,bool> visited;
    
    //traverse the list in dfs manner
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans=dfs(i,-1,visited,adj);
            if(ans==true){
                return "Yes";
            }
        }
    }
    return "No" ;
}

