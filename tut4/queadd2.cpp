#include<iostream>
#include<queue>
#include <bits/stdc++.h>
using namespace std ;
//5,11,3,10,13     2
//5,11,3,10,13     3 
//5,11,10,13,3      
 int min_index(queue<int> &q ,int sortedindex){
    int n=q.size();
    int min= INT_MAX;
    int min_index =-1;
    for (int i=0;i<n;i++){
        int curr=q.front() ;
        if (curr<min && i<sortedindex ){
           min=curr;
           min_index=i;
        }
        q.push(q.front());
        q.pop();
    }
    return min_index;
 }
 void insert(queue<int>&q, int min_index)
    {
        int element ;
        int n=q.size();
        for (int i=0;i<n;i++){
            if (i!=min_index){
            q.push(q.front());
            q.pop();
            }
        else{
            element=q.front();
            q.pop();
        }
    }
     q.push(element);
    }
    void sort(queue<int> &q){
     for (int i=0;i<q.size();i++){
        int x =min_index(q,q.size()-i);
        insert(q,x);
     }
    }
int main(){
    queue<int > q;
    q.push(5);
    q.push(11);
    q.push(3);
    q.push(10);
    q.push(13);
    sort(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
return 0;
}