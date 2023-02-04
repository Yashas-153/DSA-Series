#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef pair<int,int> pii;

#define mod int(1e9 + 7)

int NumberOfWays(int V, int E, vii edges){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<pair<int,int>> g[V];
    for(auto it: edges){
        g[it[0]].push_back({it[1],it[2]});
        g[it[1]].push_back({it[0],it[2]});
    }
    /*for(int i =0;i<V;i++){
        cout<<i<<"- >";
        for(auto it: g[i]){
            cout<<"( " <<it.first<<" , "<<it.second<<" )";
        }
        cout<<endl;
    }*/
    vi dist(V,INT_MAX);
    vi ways(V,0);
    dist[0] = 0;
    pq.push({0,0});
    ways[0] = 1;
    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        for(auto it: g[node]){
            int adjNode = it.first;
            int nextDis = it.second;
            if(dis + nextDis < dist[adjNode]){

                dist[adjNode] = nextDis + dis;
                pq.push({dis + nextDis , adjNode});
                ways[adjNode] = ways[node];
            }
            else if(dis + nextDis == dist[adjNode]){
                //cout<<"If got execued for the node "<<node<<" to adjNode "<<adjNode<<endl;
                ways[adjNode] =ways[adjNode] + ways[node];
            }   
        }
    }
    for(auto x : ways)
        cout<<x<<" ";
    cout<<endl;
    return ways[V-1];
    
}

int main(){
    int v,e;
    v= 7;
    e = 10;
    vector<vector<int>> edges =  {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    cout<<NumberOfWays(v,e,edges);
    return 0;

}