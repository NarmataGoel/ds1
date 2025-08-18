#include<iostream>
using namespace std ;
int main(){
int arr[]={1,2,3,4};
int n=sizeof(arr)/sizeof(arr[0]);
for(int i=0;i<n/2;i++){
    int temp=arr[n-1-i];
    arr[n-1-i]=arr[i];
    arr[i]=temp;
}
for (int j=0;j<n;j++){
    cout<<arr[j]<<endl;
}
return 0;
}