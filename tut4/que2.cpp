#include<iostream>
using namespace std ;
class circularqueue{
int n=10 ;
int front =-1 ;
int rare =-1;
int arr[10];
public :
bool isfull(){
    return (front == (rare+1)% n);
}
bool isempty(){
      return (front == -1 && rare == -1);
}
void enqueue( int x){
    if (isfull()){
        cout<<"queue is full"<<endl ;
    }
    else {
        if (front == -1) {  // first element case
            front = 0;
        }
        rare =(rare+1)%n;
        arr[rare]=x;
    }
}
int dequeue(){
  if (isempty()){
    cout<<"the queue is empty "<<endl ;
    return NULL;
  }
     int val = arr[front];
    if (front == rare) {  // only one element
            front = rare = -1;
        }
        else {
   front=(front+1)%n;
        }
        return val;
}
void display(){
    if (isempty()){
        cout<<"no element in queue "<<endl ;
    }
    else {
   int i=front ;
   while (true ){
    cout<<arr[i]<<" ";
    if (i==rare) break ;
    i=(i+1)%n;
   }
    cout<<endl ;
}
}
void peak(){
    if (isempty()){
        cout <<"no peak element bcz queue is empty"<<endl;
    }
    else {
        cout<<"the peak element is "<<arr[front]<<endl ;
    }
}
    int size() {
        if (isempty()) return 0;
        if (rare >= front) return rare - front + 1;
        return (n - front) + (rare + 1);
    }
void interleave(){
    if (size()%2!= 0){
        cout <<"interleave is not possible "<<endl ;
        return ;
    }
    int siz=size()/2;
    int  half[siz];
    for (int i=0;i<siz;i++){
        half[i]=dequeue();
    }
    for (int i=0;i<siz;i++){
        enqueue(half[i]);
        enqueue(dequeue());
    }
}
};
int main(){
  int arr[]={1,2,3,4,5,6};
  int n=sizeof(arr)/sizeof(arr[0]);
  circularqueue q ;
  for (int i=0;i<n;i++){
    q.enqueue(arr[i]);
  }
  cout<<"original"<<endl ;
  q.display();
 q.interleave();
  cout <<"after interleave "<<endl;
  q.display();
return 0;
}