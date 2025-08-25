#include<iostream>
using namespace std ;
int main(){
int arr[]={100,101,103,104};
int n=sizeof(arr)/sizeof(arr[0]);
int missing;
int num=1;
for(int i=1;i<n;i++){
if (arr[i]-arr[i-1]!=1){
  missing=arr[i-1]+num;
  break;
}
}
cout<<"the missing no. is"<<missing;
return 0;
}