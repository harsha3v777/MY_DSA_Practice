//detect a cycle in undirected graph

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//BFS(Breadth Frist Search)

//BFS approach will work for a fully connected undirected graph,
// but only if the graph is connected and you always start BFS from node 0

class Solution {
    private:

    public:

    bool isCycleBFS2(int V,vector<int> adj[]){
        vector<int> vis(V,0);
        queue<pair<int,int>> q;
        q.push({0,-1});
        vis[0]=1;
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==0){
                    q.push({it,node});
                    vis[it]=1;
                }else if(vis[it]==1 && it!=parent){
                    return true;
                }
            }
        }

        return false;
    }
};

//for both connected and disconnected graphs

bool isCycleBFS(int V,vector<int> adj[]){
    vector<int> vis(V,0);
    for(int start=0;start<V;start++){
        if(vis[start]==0){
            queue<pair<int,int>> q;
            q.push({start,-1});
            vis[start]=1;

            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                
                for(auto it:adj[node]){
                    if(!vis[it]){
                        vis[it]=1;
                        q.push({it,node});
                    }else if(it!=parent){
                        return true;
                    }
                }
            }
        }
    }

    return false;
};

//DFS(Deapth Frist Search)

class SolutionDFS{
    private:

    bool DFS(vector<int> adj[],vector<int> &vis,int node,int parent){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(DFS(adj,vis,it,node)==true){
                    return true;
                }
            }else if(it!=parent){
                return true;
            }
        }
        return false;
    }

    public:

    bool isCycleDFS(int V,vector<int> adj[]){
        vector<int> vis(V,0);
        for(int node=0;node<V;node++){
            if(!vis[node]){
                int parent=-1;
                 if(DFS(adj,vis,node,parent)==true){
                    return true;
                 }
            }
        }
        return false;
    }
};

int main() {
    int V = 5; // Number of vertices
    vector<int> adj[V];

    //BFS
    // Example graph edges (undirected)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(0);
    adj[0].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // Check for cycle
    if (isCycleBFS(V, adj))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;

    //DFS
     // Example 2: Graph WITH cycle (1 - 4 back edge)
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    adj[4].push_back(1);
    adj[1].push_back(4);

    SolutionDFS sol;
    if (sol.isCycleDFS(V, adj)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle" << endl;
    }

    return 0;
}