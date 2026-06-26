#include<iostream>
#include<vector>
using namespace std;


//undirected graph - MATRIX
//tc-o(n*n)

// int main(){
//     int n,m;

//     cout<<"Enter Dimensions of the matrix : ";
//     cin>>n>>m;

//     int adj[n+1][n+1]={0};

//     cout<<"Enter the connections : "<<endl;
//     for(int i=0;i<m;i++){
//         int u,v;
//         cin>>u>>v;

//         adj[u][v]=1;
//         adj[v][u]=1;
//     }

//     // Print the adjacency matrix
//     cout << "Adjacency Matrix:\n";
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= n; j++) {
//             cout << adj[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout<<"End";

//     return 0;
// }


//undirected graph - using list
//tc - o(2E)

int main(){
    int n,m;
    cout<<"Enter Dimensions of the matrix : ";
    cin>>n>>m;

    vector<int> adj[n+1];
    cout<<"Enter the connections : "<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

     // Print the adjacency list
    cout << "\nAdjacency List:\n";
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    cout << "End\n";

    return 0;


    // directed graph - using list
    //tc - o(E)

    // vector<int> adj[n+1];
    // cout<<"Enter the connections : "<<endl;
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //       // u --> v  -> directed graph
    //     adj[u].push_back(v);
    // }
}