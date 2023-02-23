#include<bits/stdc++.h>
using namespace std;

void sovle(int arr[], int dep[]){
    int ans=1;
    int count=1;
    int i=1,j=0;
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j]) //one more platform needed
        {
            count++;    
            i++;
        }
        else //one platform can be reduced
        {
            count--;
            j++;
        }
        ans=max(ans,count); //updating the value with the current maximum
    }
    return ans;
}

int main(){
    int arr[] = {900, 945, 955, 1100, 1500, 1800} ;
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int ans = solve(arr,dep);
    cout<<ans;
    return 0;

}