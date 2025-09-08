#include<iostream>
#include<stack>
#include<cctype>
using namespace std;
//infix to postindex 
int precedence(char c){
 if (c== '+' || c== '-') return 1;
    if (c== '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}
string infixtopostfix(string s){
  stack<char> st;
  string postfix="";
  for (char ch:s){
    if (isalpha(ch)){
      postfix+=ch;
    }
    else if (ch=='('){
        st.push('(');
    }
    else if (ch==')'){
       while(!st.empty() && st.top()!='('){
        postfix+=st.top();
        st.pop();
       } 
       st.pop();
       }
       else{
        while(!st.empty() && precedence(st.top())>=precedence(ch)){
        postfix+=st.top();
        st.pop();
        }
        st.push(ch);
       }
  }

  while(!st.empty()){
    postfix+=st.top();
    st.pop();
  }
     return postfix;
  }
int main(){
     string s ;
    cout<<"enter the expression ";
    getline(cin,s);
       string ans = infixtopostfix(s);
       for(auto ch:ans){
        cout<<ch;
       }
       return 0;
}