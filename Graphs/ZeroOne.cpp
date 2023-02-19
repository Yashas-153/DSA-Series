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

vector<vector<int>> nearestMy(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid[i][j] == 1 and vis[i][j] == 0){
                queue<pair<pair<int,int>,int>> q;
                q.push({{i,j},0});
                dist[i][j] = 0;
                vis[i][j] = 1;
                int drow[] = {-1,0,1,0};
                int dcol[] = {0,1,0,-1};
                while(!q.empty()){
                    int row = q.front().first.first;
                    int col = q.front().first.second;
                    int pred = q.front().second;
                    q.pop();
                    for(int i =0;i<4;i++){
                        int nrow = row + drow[i];
                        int ncol = col + dcol[i];
                        if(nrow >= 0 and nrow < n and ncol >= 0 and ncol <m and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 0 ){
                            dist[nrow][ncol] =  pred + 1;
                            q.push({{nrow,ncol},pred + 1});
                            vis[nrow][ncol] = 1;
                            cout<<i<< " "<<j<<" "<<vis[nrow][ncol]<<endl;
                        }
                    }
                } 
            } 
        }
    }
    return dist;

}


int main(){
    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };
	
	vector<vector<int>> ans = nearestMy(grid);
		
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}

    return 0;    
}