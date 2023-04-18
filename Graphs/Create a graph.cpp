// Online C++ compiler to run C++ program online
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;
template <typename T>
class Graph{
    public:
    unordered_map<T,list<T>> adj;
    void addEdge(T u,T v,bool direction){
        adj[u].push_back(v);
        if(direction==0)
            adj[v].push_back(u);
    }
    void printAdj(){
        for(auto i:adj){
            cout<<"List for "<<i.first<<" is: ";
            for(auto j:i.second){
                cout<<j<<", ";
            }cout<<endl;
        }
    }
};


int main() {
    int n;
    cout<<"Enter the no of nodes: "<<endl;
    cin>>n;
    int m;
    cout<<"Enter the no of edges: "<<endl;
    cin>>m;
    Graph<int> g;
    // g.addEdge(1,2,0);
    // g.addEdge(2,3,0);
    // g.addEdge(1,4,0);
    // g.addEdge(4,3,0);
    
    for(int i=0;i<m;i++){
        cout<<"For edge "<<i<<endl;
        int u;
        int v;
        cout<<"Enter the value of u and v "<<endl;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    
    g.printAdj();

    return 0;
}
