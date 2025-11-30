
#include<iostream>
using namespace std;

void selection(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int minIndex = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main(){
    int arr[] = {3,6,1,7,2,10};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Before: ";
    for(auto it : arr) cout << it << " ";

    selection(arr, n);

    cout << "\nAfter:  ";
    for(auto it : arr) cout << it << " ";
}
