#include<iostream>
using namespace std ;
void bubblesort(int arr[],int n){
    for (int i=0;i<n-1;i++){
          bool flag = false ;
     for (int j=0;j<n-1-i;j++){
        if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true ;
        }
     }
     if ( !flag  ){
        break ;
     }
    }
}
int main(){
int arr[]={64,34,25,12,22,11,90};
int n= sizeof(arr)/sizeof(arr[0]);
for (int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl<<"after sort"<<endl;
bubblesort(arr,n);
for (int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
return 0;
}