#include<iostream>
#include<unordered_set>
#include <algorithm>
using namespace std ;
int main(){
   int n;
   cout<<"enter the size of array"<<endl;
   cin>>n;
   int arr[n];
   cout <<"enter the elements "<<endl;
   for (int i=0;i<n;i++){
    cin>>arr[i];
   }
   //using set
   // unordered_set<int >st;
   // for (int i=0;i<n;i++){
   //  st.insert(arr[i]);
   // }
   // cout<<"the no of  distinct elements in array " <<st.size();
   
   sort(arr,arr+n); //using sort 
   int cnt =1;
   for (int i=0 ;i<n-1;i++ ){
      if (arr[i]!=arr[i+1]){
      cnt ++;
      }
   }
   cout <<"thw total distinct numbers in array is "<<cnt <<endl;
return 0;
}