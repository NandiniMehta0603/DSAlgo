#include<unordered_map>
#include<queue>
#include<list>
//steps: make an adj list-->traverse in bfs order
//in bfs-->if any node has 2 parents--> means cycle is present
void CreateAdjList(vector<vector<int>> &edges,int m,unordered_map<int,list<int>> &adj){
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

bool checkBfs(int src,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited){
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);

   
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neighbour: adj[front]){
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1;
                parent[neighbour]=front;
            }
        }
        
    }
    return false;

}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //step1: make an adj list
    unordered_map<int,list<int>> adj;
    CreateAdjList(edges,m,adj);

    //step2: create a map to store of visited
    unordered_map<int,bool> visited;
    // for(int i=0;i<n;i++){
    //     visited[i]=false;
    // }
    // string ans="";
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool result=checkBfs(i,adj,visited);
            if(result==true){
                return("Yes");
            }
        }
    }
    return("No");
    
}



