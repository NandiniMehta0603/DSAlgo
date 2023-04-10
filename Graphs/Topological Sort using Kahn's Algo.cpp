#include <bits/stdc++.h> 
#include<list>
#include<unordered_map>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //make an adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }

    //store all the indegrees
    vector<int> indegree(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    //make a queue and then traverse in bfs order
    queue<int> q;
    //push all the 0 indegree nodes
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //make an ans vector
    vector<int> ans;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        ans.push_back(front);

        for(auto nbr:adj[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    return ans;
}
