//step1: create an adj list
//make a visited list
//traverse in dfs order--> if node is not visited yet 
//on returning back, if the node has no more neighbours to be visited-->
//then push the nodes into the stack
//we are using a stack bec otherwise we will have the ans in reverse order

#include <bits/stdc++.h> 
#include<list>
#include<unordered_map>
#include<stack>
void createAdj(vector<vector<int>> &edges,int e,unordered_map<int,list<int>> &adj){
    // int row=edges.size();
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }
}

void dfs(int src,unordered_map<int,list<int>> &adj,stack<int> &st,vector<bool> &vis){
    vis[src]=true;
    for(auto nbr:adj[src]){
        if(vis[nbr]==false){
            dfs(nbr,adj,st,vis);
        }
    }
    st.push(src);
}


vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //step1: make adj list
    unordered_map<int,list<int>> adj;
    createAdj(edges,e,adj);
    
    //step2: make a visited list
    // unordered_map<int,bool> vis;
    // for(int i=0;i<v;i++){
    //     vis[i]=false;
    // }
    vector<bool> vis(v);
    //step3: traverse in dfs order and store nodes in stack
    stack<int> st;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,adj,st,vis);
        }
    }
    //step4: make an ans arr and return the ans
    vector<int> ans;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        ans.push_back(top);
    }
    return ans;
}
