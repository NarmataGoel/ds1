#include<iostream>
using namespace std ;
int main(){
int arr[]={1,2,5,10,0,3};
int n=sizeof(arr)/sizeof(arr[0]);
bool flag =true ;
for(int i=0;i<n-1;i++){
    for (int j=0;j<n-1-i;j++){
        if (arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            flag=false;
        }
    }
    if (flag){
    break;
    }
}
for (int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}
return 0;
}