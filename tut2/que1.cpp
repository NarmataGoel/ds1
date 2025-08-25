#include<iostream>
using namespace std ;
 int binary(int arr[],int num,int n){
    int low=0;
    int high =n-1;
  while (high >low){
    int mid = low+(high-low)/2;
    if (arr[mid]==num){
        return mid+1;
      break;
    }
        else if (arr[mid]>num){
        high=mid-1;
        }
        else {
        low =mid+1;
        }
    }
    return -1;
 }
int main(){
  int arr[]={1,2,3,4,6,8,9,14,45};
  int num;
  cout<<"enter the number u want to search ";
  cin>>num;
  int n=sizeof(arr)/sizeof(arr[0]);
  int x=binary(arr,num,n);
  if (x==-1){ cout<<"number can not found ";}
  else{ cout<<"your no. found at "<<x<<"postion";}
return 0;
}