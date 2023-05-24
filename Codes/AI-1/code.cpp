#include<bits/stdc++.h>
using namespace std;

class Graph{
    void edge(int src,int dest){
        lst[src].push_back(dest);
        lst[dest].push_back(src);
    }
    public:
    vector<vector<int>> lst;
    Graph(int n,int e){
        lst.resize(n);
        for(int i=0;i<e;i++){
            cout<<"Enter 2 vertices: ";
            int a,b;
            cin>>a>>b;
            edge(a,b);
        }
    }

    void bfs(Graph const &graph,queue<int> &q,vector<bool> &discoverd){
        if(q.empty()){
            return;
        }
        int vi = q.front();
        q.pop();
        cout<<vi<<" ";

        for(int u:graph.lst[vi])
        {
             if(!discoverd[u]){
                discoverd[u] = true;
                q.push(u);
            }

        }
       
        bfs(graph,q,discoverd);
    }

    void dfs(Graph const &graph,stack<int> &s,vector<bool> &discovered1){
        if(s.empty()){
            return;
        }
        int vi = s.top();
        s.pop();
        cout<<vi<<" ";
        for(int u:graph.lst[vi])
        {
            if(!discovered1[u]){
                discovered1[u] = true;
                s.push(u);
            }

        }
        dfs(graph,s,discovered1);
    }
};

int main()
{
  int n,e;
  cout<<"count of vertices & edges: ";
  cin>>n>>e;
  Graph g(n,e);
  vector<bool>discoverd(n,false);
  vector<bool>discoverd1(n,false);
  queue<int>q;
  stack<int>s;

    // bfs
    cout<<"BFS: \n";
    for(int i=0;i<n;i++){
        if(!discoverd[i]){
            discoverd[i] = true;
            q.push(i);
            g.bfs(g,q,discoverd);
        }
    }
    
    // dfs
    cout<<"\nDFS:\n";
    for(int i=0;i<n;i++){
        if(!discoverd1[i]){
            discoverd1[i] = true;
            s.push(i);
            g.dfs(g,s,discoverd1);
        }
    }
  
    return 0;
}