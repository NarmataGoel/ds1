#include<iostream>
using namespace std ;
class queue{
   int n=5;
   int front =-1;
   int rare =-1;
   public :
   int arr[5];
   bool isempty(){
    return (front==-1 && rare==-1 || front>rare ) ; 
   }
   bool isfull(){
    return (rare==n-1);
   }
   void enqueue(){
    if (rare ==n-1 || isfull() ){
        cout<<"the queue is full "<<endl ;
    }
    else{
        int x ;
        cout<<"enter the element u want in "<<endl;
        cin>>x;
        rare++;
        arr[rare]=x;
    }
   }
   void dequeue(){
    if(isempty()){
        cout<<"the queue is empty"<<endl ;
    }
    else {
        front++;
        if (front ==n-1){
            front=-1 ;
            rare=-1;
        }
    }
   }
   void display(){
    if (isempty()){
        cout<<"the queue is empty "<<endl ;
    }
    else {
        for (int i=front ;i<=rare ;i++){
        cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
   }
   void peak(){
    if (isempty()){
        cout <<"no peak element bcz queue is empty "<<endl ;
    }
    else {
        cout<<"the peak element is "<< arr[front]<<endl;
    }
   }
};
int main(){
  bool check=true ;
  queue q;
  int x ;
  while (check){
    cout<<"select no for following operations :"<<endl << "1. insert an element in  queue "<<endl <<"2. delect an element in queue"<<endl<<"3. display queue elements "<<endl<<"4. show peak element "<<endl<<"5. end the menu "<<endl ;
    cin>>x ;
    switch (x)
    {
    case 1:
       q.enqueue();
        break;
    case 2: 
    q.dequeue();
    break;
    case 3:
    q.display();
    break; 
    case 4 :
    q.peak();
    break;
    case 5:
    check= false ;
    cout <<"THE END ";
    break;
    default:
    cout <<"no valid number choose"<<endl;
        break;
    }
  }
return 0;
}