#include<iostream>
using namespace std ;

int main(){
  int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
  int row=sizeof(arr)/sizeof(arr[0]);
  int col=sizeof(arr[0])/sizeof(arr[0][0]);
  int sum[row]={0};
  int sum1[col]={0};
  for (int i=0;i<row;i++){
    for(int j=0;j<col;j++){
    sum[i]+=arr[i][j];
}
  }
    for (int i=0;i<col;i++){
    for(int j=0;j<row;j++){
    sum1[i]+=arr[j][i];
}
  }
  cout<<"the sum of row is "<<endl;
  for (int i=0;i<row;i++){
    cout<<i+1<<"row -"<<sum[i]<<endl;
  }
   cout<<"the sum of column is "<<endl;
  for (int j=0;j<col;j++){
    cout<<j+1<<"col -"<<sum1[j]<<endl;
  }
return 0;

}