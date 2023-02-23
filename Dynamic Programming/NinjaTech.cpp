#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vii;

int getmax(vii points, int day, int last,vii &dp){
    
    if(day == 0){
        int maxi = 0;
        for(int i =0;i<3;i++){
            if(i != last){
             maxi = max(maxi, points[0][i]);
            }
        }
        return dp[day][last] = maxi;
    } 
    
    if(dp[day][last] != -1){
        return dp[day][last];
    }
    
    
    int pts = 0;
    int maxi = 0;
    for(int i =0;i<3;i++){
        if( i != last){
            pts = points[day][i] + getmax(points,day-1,i,dp);
            maxi = max(pts,maxi);
        }
    }
    return dp[day][last] = maxi ;

}

int findmax(vii points){
    int last = 3;
    int day = points.size();
    vii dp(points.size(),vector<int>(4,-1));
    return getmax(points,day-1,last,dp);
}

int main(){
    vii points ={{10,40,70},
                 {20,50,80},
                 {30,60,90}};

    cout<<findmax(points)<<endl;


    return 0;
}