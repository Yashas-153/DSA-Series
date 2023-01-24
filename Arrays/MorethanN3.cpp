#include<bits/stdc++.h>
using namespace std;

// Boyer Moore’s Voting Algorithm1 :  
// Finding two or one number which may have occurred a maximum number of times than another element.
vector<int> morethanN3(vector<int> arr){
    int n = arr.size();
    int count1 = 0,count2 = 0 ,first=0,second = 0;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (first == arr[i])
            count1++;
        else if (second == arr[i])
            count2++;
      
        else if (count1 == 0) {
            count1++;
            first = arr[i];
        }
  
        else if (count2 == 0) {
            count2++;
            second = arr[i];
        }
        else {
            count1--;
            count2--;
        }
        cout<<"First num : "<<first<<" count : "<<count1<<endl;
        cout<<"Second num : "<<second<<"count : "<<count2<<endl;
    }
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == first)
            count1++;
  
        else if (arr[i] == second)
            count2++;
    }
      
    if (count1 > n / 3){
        cout << first << " ";
          flag=1;
    }
    if (count2 > n / 3){
        cout << second << " ";
          flag=1;
    }
      if(flag==0){
          cout << "No Majority Element" << endl;
    }
}

int main(){
    vector<int> arr = {7,7,7,4,3,4,4,4,5};

    return 0;
}