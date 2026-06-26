#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent,rank;

public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u == ulp_v) return;

        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v]=ulp_u;
        }else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }else{ // rank[u] == rank[v]
            parent[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main(){
    DisjointSet ds(7);

    ds.UnionByRank(1,2);
    ds.UnionByRank(2,3);
    ds.UnionByRank(4,5);
    ds.UnionByRank(6,7);
    ds.UnionByRank(5,6);

    //if 3 and 7 are connected or not
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"They are in same component";
    }else{
        cout<<"They are not in same component";
    }
    cout<<endl;

    ds.UnionByRank(3,7);

    //if 3 and 7 are connected or not
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"They are in same component";
    }else{
        cout<<"They are not in same component";
    }
    cout<<endl;
}