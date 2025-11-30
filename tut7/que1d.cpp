#include<iostream>
using namespace std ;
void mergesort(int arr[],int low,int mid ,int high){
    int right=mid+1;
    int left=low;
    int temp[high -low +1];
    int index=0;
    while (left<=mid && right<=high){
        if (arr[left]>arr[right]){
            temp[index]=arr[right];
            right++;
            index++;
        }
        else {
            temp[index]=arr[left];
            index++;
            left++;
        }
    }
       while  (left<=mid){
          temp[index]=arr[left];
            index++;
            left++;
        }
        while (right<=high){
         temp[index]=arr[right];
            right++;
            index++;    
        }
        for (int i=low;i<=high;i++){
         arr[i]=temp[i-low];
        }
}
void ms (int arr[],int low ,int high ){
    if (low<high){
        int mid=low+(high-low)/2;
        ms(arr,low,mid-1);
        ms(arr,mid+1,high);
        mergesort(arr,low,mid,high);
    }
}
int main(){
int arr[]={1,3,6,2,5};
int n=sizeof(arr)/sizeof(arr[0]);
ms(arr,0,n-1);
for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
}
return 0;
}