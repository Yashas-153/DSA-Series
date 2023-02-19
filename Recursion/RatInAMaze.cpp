#include<bits/stdc++.h>
using namespace std;

void getAllPaths(vector<vector<int>> maze,int n, vector<string> &ans,vector<vector<int>> &vis, string out,int row, int col){
    if(row == n-1 and col == n-1){
        ans.push_back(out);
        return;
    }
    // D L R U
    int drow[] = {1,0,0,-1};
    int dcol[] = {0,-1,1,0};
    char abb[] = {'D','L','R','U'};
    for(int i = 0;i<4;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow >= 0 and nrow < n and ncol >= 0 and ncol <n and vis[nrow][ncol] != 1 and maze[nrow][ncol]== 1){
            vis[row][col] = 1;
            out.push_back(abb[i]);
            getAllPaths(maze,n,ans,vis,out, nrow,ncol);
            out.pop_back();
            vis[row][col]= 0;
        }
    }
   // vis[row][col] = 0;
}

vector<string> findPath(vector<vector<int>> maze, int n){
    vector<string> ans;
    vector<vector<int>> vis(n,vector<int>(n,0));
    getAllPaths(maze,n,ans,vis,"",0,0);
    return ans;

}

int main(){
    vector<vector<int>> maze ={{1, 0, 0, 0},
        {1, 1, 0, 1}, 
        {1, 1, 0, 0},
        {0, 1, 1, 1}};
    vector<string> ans = findPath(maze,4);
    for(auto x: ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}