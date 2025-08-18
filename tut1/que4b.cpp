#include<iostream>
using namespace std ;
int main(){
int arr[2][3]={{1,2,3},{4,5,6}};
int arr1[3][2]={{1,2},{3,4},{5,6}};
int ans[2][2]={0};
for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
        for (int k=0;k<3;k++){
            ans[i][j]+=arr[i][k]*arr1[k][j];
        }
    }}
for (int i=0;i<2;i++){
    for (int j=0;j<2;j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}