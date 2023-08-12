#include<bits/stdc++.h>
void dfs(int node,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &vis,stack<int> &st){
    vis[node]=true;
    for(auto nbr:adj[node]){
        if(!vis[nbr]){
            dfs(nbr,adj,vis,st);
        }
    }
    st.push(node);
}
void revdfs(int node,unordered_map<int,vector<int>> &transpose,unordered_map<int,bool> &vis){
    vis[node]=true;
    for(auto nbr:transpose[node]){
        if(!vis[nbr]){
            revdfs(nbr,transpose,vis);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    unordered_map<int,bool> vis;
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,adj,vis,st);
        }
    }

    unordered_map<int, vector<int>> transpose;
    for(int i=0;i<v;i++){
        vis[i]=0;
        for(auto nbr: adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    int count=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!vis[top]){
            count++;
            revdfs(top,transpose,vis);
        }
    }
    return count;
}
