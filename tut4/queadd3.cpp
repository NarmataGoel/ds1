#include<iostream>
#include<queue>
#include<stack>
using namespace std ;
bool check (queue<int>& q){
    int expected =1;
    stack<int > st ;
    queue<int > q1 ;
    while(!q.empty()){
       while(!q.empty() && expected ==q.front()){
        q1.push(q.front());
        q.pop();
        expected++;
       }
       while(!st.empty() && expected ==st.top()){
        q1.push(st.top());
        st.pop();
        expected ++;
       }
       if (!q.empty()) {
            if (st.empty() || st.top() > q.front()) {
                st.push(q.front());
                q.pop();
            } else {
                return false; 
            }
        }
    }
     while (!st.empty() && st.top() == expected) {
        q1.push(st.top());
        st.pop();
        expected++;
    }
    return st.empty();
}
int main(){
queue<int > q ;
int arr[]={5,1,2,6,3,4};
int n=sizeof(arr)/sizeof(arr[0]);
for (int i=0;i<n;i++){
 q.push(arr[i]);
}
if(check(q)) cout<<"true"<<endl;
else cout<<"false" ;
return 0;
}