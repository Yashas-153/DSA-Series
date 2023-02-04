#include<bits/stdc++.h>
using namespace std;

void shortestPath(vector<vector<int>> list, int src){
    int n = list.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<pair<int,int>> g[n];
    for(auto it: list){
        g[it[0]].push_back({it[1],it[2]});
        g[it[1]].push_back({it[0],it[2]});
    }
    /*for(int i =0;i<n;i++){
        cout<<i<<"- >";
        for(auto it: g[i]){
            cout<<"( " <<it.first<<" , "<<it.second<<" )";
        }
        cout<<endl;
    }*/
    
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;
    pq.push(make_pair(0,src));
    cout<<"size of pq is "<<pq.size();
    while(!pq.empty()){
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for(auto it: g[node]){
            int next = it.first;
            int nextdis = it.second;

            if(dist[next] > nextdis + dist[node] ){
                dist[next] = nextdis + dist[node];
                pq.push(make_pair(dist[next],next));
            }
        }
    }
    cout<<"all the shortest from src is "<<endl;
    for(int i =1;i<n;i++){
        cout<<dist[i]<<" ";
    }

}

int main(){
    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, -2}, {1, 4, -1}, {4, 3, -3}, 
    {3, 5, 1}};
    int src = 1;
    shortestPath(edges, src);
    return 0;
}