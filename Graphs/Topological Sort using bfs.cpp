#include <bits/stdc++.h> 
#include<unordered_map>
#include<list>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //step1: make an adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
    }
    //find all the indegrees
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    //push all the 0 indegree nodes
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //traverse in bfs order
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();

        //ans store
        ans.push_back(front);

        //update nbr
        for(auto nbr: adj[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    return ans;
}
