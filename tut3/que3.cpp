#include<iostream>
using namespace std ;
struct stack {
    int m=100;        
    int s[100];      
    int t = -1;   

    bool isfull() {
        return (t == m - 1);
    }

    bool isempty() {
        return (t == -1);
    }

    void push(int x) {
        if (isfull()) {
        } else {
            t++;
            s[t] = x;
        }
    }

    void pop() {
        if (isempty()) {
        } else {
            t--;
        }
    }

    char peek() {
        if (isempty()) {
        } else {
            return s[t];
        }
    }
};
bool isbalanced(string s){
   stack st;
  for (int i=0;i<s.size();i++){
  char ch=s[i];
   if(ch=='('|| ch=='{' || ch=='['){
    st.push(ch);
   }
   else{
    if(ch==')' && st.peek()!='(' || ch=='}' && st.peek()!='{' || ch==']' && st.peek()!='['  ){
      return false;
    }
    st.pop();
   }
   }
   return (st.isempty()) ;
}
int main(){
    cout<<"enter string"<<endl;
    string s;
    cin>>s;
   if(isbalanced(s)){
    cout<<"ys it is a balanced parenthesis"<<endl;
   }
   else {
    cout<<"not a valid parenthesis"<<endl;
   }
return 0;
}