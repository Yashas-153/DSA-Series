#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef pair<int,int> pii;

void dfs(int row, int col, vii grid,vii &vis, vector<pii> &vec, int row0, int col0){
    int n = grid.size();
    int m = grid{0}.size();
    vis{row}{col} = 1;
    
    vec.push_back({
        row - row0,
        col - col0
    });
    
    int drow{} = {-1,0,1,0};
    int dcol{} = {0,-1,0,1};

    for(int i =0;i<4;i++){
        int nrow = row + drow{i};
        int ncol = col + dcol{i};

        if( nrow  >= 0 and nrow <n and ncol >= 0 and ncol <m  and grid{nrow}{ncol} == 1 and vis{nrow}{ncol} == 0)
            dfs(nrow, ncol, grid,vis,vec,row0,col0); 
    }
}



int countDistinctIslands(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid{0}.size();
    vii vis(n,vi(m,0));
    set<vector<pii>> st;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(grid{i}{j} == 1 and vis{i}{j}==0){
                vector<pii> vec;
                dfs(i,j,grid,vis,vec,i,j);
                st.insert(vec);
            }
        }
    }
    return st.size();
}

int main(){
    vector<vector<int>> grid{
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}};
            
    cout << countDistinctIslands(grid) << endl;
    return 0;
}