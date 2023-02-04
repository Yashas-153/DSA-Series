#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int vis[], vector<int> adj[],int dfsvis[], int &count){
    vis[node] = 1;
    dfsvis[node] = 1;
    //count++;
    for(auto adjNode:adj[node]){
        if(vis[adjNode] == 0){
            count++;
            //cout<<"adjnode is "<<adjNode<<endl;
            //cout<<"count is "<<count<<endl;
            if(dfs(adjNode,  vis,adj,dfsvis,count)==true){
                //cout<<"Return true from here for the node "<<adjNode<<endl;
                return true;
            }
        }
        else if(dfsvis[adjNode] == 1){
            //count = 0;
            //cout<<"returned true for node "<<adjNode<<endl;
            return true;
        }
    }
    count = 0;
    dfsvis[node] = 0;
    //cout<<"returned false for node  "<<node<<endl;
    return false;
}

int iscycle(int V,vector<int> arr){
    vector<int> adj[V];
    for(int i =0;i<V;i++){
        if(arr[i]!= -1)
            adj[i].push_back(arr[i]);
    }
    int count = 0;
    int vis[V] = {0};
    int dfsvis[V] = {0}; 
    int sum = 0;
    int max_cnt = 0;
    for(int i =0;i<V;i++){
        if(vis[i]==0)
            if(dfs(i, vis, adj,dfsvis,count) == true){
                //cout<<" count in For is "<<count<<endl;
                max_cnt = max(count,max_cnt);  
            }
    }
    return max_cnt;
}

int main(){
    vector<int> arr = {
       4, 4, 1, 4, 13, 8, 8, 8, 0, 8, 14, 9, 15, 11, -1, 10, 15, 22, 22, 22, 22, 22, 21
    };

    int sum = iscycle(arr.size(), arr);
    cout<<"sum is "<<sum + 1<<endl;
    return 0;
}