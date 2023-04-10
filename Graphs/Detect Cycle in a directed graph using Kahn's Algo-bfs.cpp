//with the help of kahn's algo-->if the count==n then no cycle is present
//else the cycle is present
#include<list>
#include<unordered_map>
#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    int e=edges.size();
    
    //step1: make an adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u=edges[i].first-1;
        int v=edges[i].second-1;
        
        adj[u].push_back(v);
    }

    //step2: take out the indegrees
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    //step3: make a queue and push all the 0 indegree nodes
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    //comapre using count
    int count=0;
    while(!q.empty()){
        int front=q.front();
        count++;
        q.pop();
        
        //update the nbrs
        for(auto nbr:adj[front]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    if(count==n){
        return false; //no cycle present
    }
    return true;
}
