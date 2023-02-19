#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[],vector<int> &vis, stack<int> &st){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]){
    cout<<"caled toposort"<<endl;
    vector<int> ans;
    vector<int> vis(V,0);
    stack<int> st;
    for(int i =0;i<V;i++){
        //cout<<"on node "<<i<<endl;
        if(!vis[i]){
           // cout<<"dfs called for "<<i<<endl;
            dfs(i,adj,vis,st);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	vector<int> ans = topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;
}