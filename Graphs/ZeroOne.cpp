#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> nearest(vector<vector<int>> mat){
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<pair<int, int>,  int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dis(n,vector<int>(m,-1));
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(mat[i][j] == 1){
                q.push({{i,j},0});
                cout<<"added"<<"{ "<<i<<" , "<<j<<" }"<<" "<<0<<endl;
                vis[i][j] = 1;
            }
        }
    }

    int distm= 0;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        dis[r][c] = dist;
        for(int i = 0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            //distm = min(dist, distm);
            if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and  vis[nrow][ncol]== 0){
                q.push({{nrow,ncol},dist+1});
                cout<<"added"<<"{ "<<nrow<<" , "<<ncol<<" }"<<" "<<dist+1<<endl;
                vis[nrow][ncol] = 1;
            }
        }
    }
    return dis;
}


int main(){
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	vector<vector<int>> ans = nearest(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

    return 0;    
}