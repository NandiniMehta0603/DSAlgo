//steps: traversing the graph using bfs always gives the shortest path
//so make a parent array containing parent of each node
//by the end whatever is the src and det--> according to that map the parent array and then take out the ans vector
#include<unordered_map>
#include<list>
#include<queue> //since we are traversing in bfs order
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	//step1: make and adj list
    //n-> no of nodes
    //m->no of edges -->bidirectional
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //make a parent arr and visited arr
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;

    //make a queue
    queue<int> q;
    q.push(s);
    parent[s]=-1;
    visited[s]=true;

    while(!q.empty()){
        int front=q.front();
        q.pop();
        //check for nbrs
        for(auto nbr:adj[front]){
            if(!visited[nbr]){
                q.push(nbr);//queue mei push kardo
                parent[nbr]=front;//parent update kardo
                visited[nbr]=true;//visited also update 
            }
        }
    }
    //here we get the fully updated parent array
    //destination node is t
    vector<int> ans;
    //backtrack
    int i=t;
    ans.push_back(t);
    while(i!=s){
        i=parent[i];
        ans.push_back(i);
    }
    reverse(ans.begin(),ans.end());
    return ans;

}
