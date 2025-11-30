#include<iostream>
#include <bits/stdc++.h>
using namespace std ;
int main(){
int arr[]={1,3,6,2,5};
int n=sizeof(arr)/sizeof(arr[0]);
for (int i=0;i<n;i++){
    int j=i;
    while ( j>0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
    }
}
for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}
return 0;
}