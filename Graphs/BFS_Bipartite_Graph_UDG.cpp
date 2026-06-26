//Bipartite graph undirected graph Breath first search (BFS)

#include <bits/stdc++.h>
using namespace std;


//t.c => O(n)*[O(n)+O(2e)]
//s.c => O(n)+O(n)

class Solution{

//BFS

private:

bool check(int start,int color[], vector<int> adj[]){
    queue<int> q;
    q.push(start);
    color[start]=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto it:adj[node]){
            if(color[it]==-1){
                color[it]= !color[node];
                q.push(it);
            }else if(color[it]==color[node]){
                return false;
            }
        }
    }

    return true;
}

public:
    bool isBipartite(int V, vector<int> adj[])  {
        int color[V];
        for(int i=0;i<V;i++) color[i]=-1;

        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(check(i,color,adj)==false){
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    int V = 4;
    vector<int> adj[V];

    // Example graph: Bipartite
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    Solution obj;
    bool ans = obj.isBipartite(V, adj);

    if (ans) cout << "Graph is Bipartite\n";
    else cout << "Graph is NOT Bipartite\n";

    return 0;
}
