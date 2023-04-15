// a spanning tree is when you can convert a graph into a tree
// ie n nodes and n-1 edges
// every node is also reachable from the other 
// calculate such that it gives mini cost of weights
// there is requirement of 3 data structures
// key, mst, parent

#include <bits/stdc++.h> 
#include<unordered_map>
#include<limits.h>
#include<list>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //step1: make adj list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<g.size();i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int wt=g[i].second;

        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }

    //step2: make additional data structures 
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    for(int i=1;i<=n;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }

    //step3: follow the algo

    key[1]=0;
    parent[1]=-1;

    for(int i=1;i<n;i++)//as there are vertices-1 rounds
    {
        int mini=INT_MAX;
        int u;
        //step a: find the min value
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }

        //step b:
        mst[u]=true;

        //step c: check the adj nodes 
        for(auto nbr:adj[u]){
            int v=nbr.first;
            int w=nbr.second;
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }

    //step4: return the ans
    vector<pair<pair<int,int>,int>> result;
    for(int i=2;i<=n;i++){
        result.push_back({{parent[i],i},key[i]});
    }
    return result;
}

 
