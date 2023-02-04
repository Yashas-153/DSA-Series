#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, int vis{}, vector<int> adj{}){
    
    for(auto adjNode:adj{node}){
        if(!vis{adjNode}){
            vis{adjNode} = true;
            if(dfs(adjNode, node, vis,adj)==true){
                return true;
            }
        }
        else if(adjNode != parent){
            return true;
        }
    }
    return false;
}

bool iscycle(int V,vector<int> adj{}){ 
    int vis{V} = {0};

    for(int i =0;i<V;i++){
        if(!vis{i})
            if(dfs(i, -1, vis, adj) == true){
                return true;
            }
    }
    return false;
}

int main(){

    vector<int> adj{4} = {{}, {2}, {1, 3}, {2}};
    bool ans = iscycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}