#include<iostream>
#include<queue>
using namespace std ;
class stack{
queue<int>q ;
int n=0;
int x;
public:
int size(int y){
   x=y;
}
void push(int num){
    if (n==x){
        cout<<"the stack is full"<<endl;
    }
    else {
        n++;
   q.push(num);
  for (int i=0;i<n-1;i++){
    q.push(q.front());
    q.pop();
  }
}
}
void pop1(){
   if (q.empty()){
     cout<<"the stack is empty"<<endl ;
   }
   else {
    q.pop();
    n--;
   }
}
void peak(){
    if(q.empty()){
        cout<<"no peak element "<<endl ;
        }
        else {
            cout<<q.front()<<endl;
        }
}
};
int main(){
   int arr[]={1,2,3,4,5} ;
   int n=sizeof(arr)/sizeof(arr[0]);
   stack st;
   st.size(n);
   for (int i=0;i<n;i++){
    st.push(arr[i]);
   }
   st.pop1();
   st.peak();
   st.pop1();
   st.peak();
return 0;
}