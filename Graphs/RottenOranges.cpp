#include<bits/stdc++.h>
using namespace std;

int rottenorange(vector<vector<int>> mat){
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<pair<int, int>,  int>> q;
    vector<vector<int>> vis(n,vector<int>(m,0));
    int t = 0;
    int cntFresh = 0;
    int cnt = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(mat[i][j] == 1){
                cntFresh++;
            }
            if(mat[i][j] == 2){
                q.push({{i,j},0});
                cout<<"added"<<"{ "<<i<<" , "<<j<<" }"<<" "<<0<<endl;
                vis[i][j] = 2;
            }
        }
    }
    int tm = 0;
    int drow[] = {-1,0,1,0};
    int dcol[] = {0,1,0,-1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        tm = max(tm,t);
        q.pop();
        for(int i = 0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            
            if(nrow >= 0 and nrow<n and ncol>=0 and ncol <n and mat[nrow][ncol] == 1 and vis[nrow][ncol]== 0){
                cnt++;
                q.push({{nrow,ncol},t + 1});
                cout<<"added"<<"{ "<<nrow<<" , "<<ncol<<" }"<<" "<<t+1<<endl;
                vis[nrow][ncol] = 2;
            }
        }
    }
    if(cnt != cntFresh){
        return -1;
    }
    return tm;
}


int main(){
    vector<vector<int>> arr = {{0,1,2},{0,1,1},{2,1,1}};
    cout<<rottenorange(arr);
    return 0;
}