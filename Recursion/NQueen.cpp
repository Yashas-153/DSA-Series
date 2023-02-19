#include<bits/stdc++.h>
using namespace std;


bool isSafe(int row, int col , vector<vector<int>> b){
    int drow = row;
    int dcol = col;
    //checking row;
    while(dcol >= 0){
        if(board[drow][dcol--] == 1){
            return false;
        }
    }
    //checking upleft
    dcol = col;
    while(drow >= 0 or dcol >= 0){
        if(board[drow--][dcol--] == 1){
            return false;
        }
    }
    //checking downleft 
    drow = row;
    dcol = col;
    while(drow <n 0 or dcol >= 0){
        if(board[drow++][dcol--] == 1){
            return false;
        }
    }

    return true;

}

bool queen(int col,int n, vector<vector<int>> &board){
    if(col >= N){
        return true;
    }

    for(int i = 0;i<n;i++){

        if(isSafe(i, col,board)){
            board[i][col] = 1;

            if(queen(col+1,n,board)){
                return true;
            }
            board[i][col] = 0;
        }
    }
    return false;
}



void solve(int n){
    vector<vector<int>> board(n,vector<int>(n,0));
    queen(0,0,n,board);
    for(auto it : x){
        for(auto ele : x){
            cout<<ele<<" ";
        }
        cout<<endl;
    }

}

int main(){

    int n = 4;
    solve(n);
    return 0;
}