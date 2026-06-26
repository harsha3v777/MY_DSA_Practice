#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> parent,size;

public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUPar(int node){
        if(node == parent[node]) return node;

        return findUPar(parent[node]);
    }

    void UnionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{ 
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

int main(){
    DisjointSet ds(7);

    ds.UnionBySize(1,2);
    ds.UnionBySize(2,3);
    ds.UnionBySize(4,5);
    ds.UnionBySize(6,7);
    ds.UnionBySize(5,6);

    //if 3 and 7 are connected or not
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"They are in same component";
    }else{
        cout<<"They are not in same component";
    }
    cout<<endl;

    ds.UnionBySize(3,7);

    //if 3 and 7 are connected or not
    if(ds.findUPar(3) == ds.findUPar(7)){
        cout<<"They are in same component";
    }else{
        cout<<"They are not in same component";
    }
    cout<<endl;
}