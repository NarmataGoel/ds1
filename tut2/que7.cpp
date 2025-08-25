#include<iostream>
using namespace std ;
int main(){
int arr[]={2,4,1,6,3};
int cnt =0;
int n=sizeof(arr)/sizeof(arr[0]);
for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++){
        if (arr[i]>arr[j]){
            cnt++;
        }                      
    }
}
cout<<"the no of inversions is "<<cnt ;
return 0;
}