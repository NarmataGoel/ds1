#include<iostream>
#include<vector>
using namespace std ;
int main(){
int arr[4][2]={{1,2},{4,5},{6,7},{3,8}};
int rows = sizeof(arr) / sizeof(arr[0]);         
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]);     
int ans[cols][rows];
for (int i=0;i<rows;i++){
    for (int j=0;j<cols;j++){
     ans[j][i]=arr[i][j];
    }
}
for (int i=0;i<cols;i++){
    for (int j=0;j<rows;j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}