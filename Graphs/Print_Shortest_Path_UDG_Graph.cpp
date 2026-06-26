#include <bits/stdc++.h>
using namespace std;

class Solution {
public: //t.c - O(E*log(V)+N)
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);

        for(int l=0;l<=n;l++){
            parent[l]=l;
        }

        dist[1]=0;
        pq.push({0,1});

        while(!pq.empty()){
            int length=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto nbr: adj[node]){
                int nextNode=nbr.first;
                int wt=nbr.second;
                if(dist[nextNode] > dist[node]+wt){
                    dist[nextNode] = dist[node]+wt;
                    pq.push({dist[nextNode], nextNode});
                    parent[nextNode] = node;
                }
            }
        }

        if(dist[n]==1e9){
            return {-1};
        }
        
        //O(N)
        vector<int> ans;
        int k=n;
        while(parent[k]!=k){
            ans.push_back(k);
            k=parent[k];
        }
        ans.push_back(k); // push root (1)

        reverse(ans.begin(), ans.end());

        // include distance at front
        ans.insert(ans.begin(), dist[n]);

        return ans;
    }
};

int main() {
    // 🔹 Hardcoded input
    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 3, 4},
        {2, 3, 1},
        {2, 4, 7},
        {3, 5, 3},
        {4, 5, 1}
    };

    Solution obj;
    vector<int> result = obj.shortestPath(n, m, edges);

    cout << "Shortest Path: ";
    for(int x: result){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
