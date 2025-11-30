#include<iostream>
using namespace std ;
int partition(int arr[],int low ,int high);
void qs(int arr[],int low,int high ){
    if (low<high){
   int index =partition(arr,low,high);
   qs(arr,low ,index-1);
   qs(arr,index+1,high);
}
}
int  partition (int arr[],int low,int high){
    int i=low ;
    int j=high ;
    int pivot =arr[low ];
    while (i<j){
        while (pivot>=arr[i]){
            i++;
        }
        while (pivot<arr[j]){
            j--;
        }
        if (i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
int main(){
int arr[]={1,3,6,2,5};
int n=sizeof(arr)/sizeof(arr[0]);
qs(arr,0,n-1);
for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}
return 0;
}