#include <bits/stdc++.h> 
#include<unordered_map>
#include<set>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //step1: make adjacency list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u=vec[i][0];
        int v=vec[i][1];
        int weight=vec[i][2];

        adj[u].push_back(make_pair(v,weight));
        adj[v].push_back(make_pair(u,weight));
    }
    

    //step2: make a distance array with infinite values 
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++){
        dist[i]=INT_MAX;
    }

    //step2: create the set
    set<pair<int,int>> st;

    dist[source]=0;
    st.insert(make_pair(0,source));
    while(!st.empty()){
        auto top=*(st.begin());
        int nodeDistance=top.first;
        int topNode=top.second;

        st.erase(st.begin());

        for(auto nbr:adj[topNode]){
            if(nodeDistance+nbr.second<dist[nbr.first]){
                auto record=st.find(make_pair(dist[nbr.first],nbr.first));
                if(record!=st.end()){
                    st.erase(record);
                }
                //distance update
                dist[nbr.first]=nodeDistance+nbr.second;
                st.insert(make_pair(dist[nbr.first],nbr.first));
            }
        }
    }
    return dist;
}
