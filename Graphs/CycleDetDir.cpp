#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, int vis[], vector<int> adj[],int dfsvis[], int &count){
    vis[node] = 1;
    dfsvis[node] = 1;
    for(auto adjNode:adj[node]){
        if(vis[adjNode] == 0){
            //cout<<"adjNode "<<adjNode <<" had not visited "<<endl;
            count++;

            if(dfs(adjNode,  vis,adj,dfsvis,count)==true){
                return true;
            }
            else if(dfsvis[adjNode] == 1){
                //cout<<"returned true for node "<<node<<endl;
                return true;
            }
        }
    }
    count--;
    dfsvis[node] = 0;
    //cout<<"returned false for node  "<<node<<endl;
    return false;
}

bool iscycle(int V,vector<int> arr){
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
                max_cnt = max(count,max_cnt);  
            }
    }
    return max_cnt;
}

int main(){
    vector<int> arr = {
       4, 4, 1, 4, 13, 8, 8, 8, 0, 8, 14, 9, 15, 11, -1, 10, 15, 22, 22, 22, 22, 22, 21
    };

    bool sum = iscycle(arr.size(), arr);
    if (sum)
        cout<<"sum is "<<sum<<endl;
    else
        cout << -1;
    return 0;
}