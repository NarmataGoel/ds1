#include<iostream>
#include<stack>
#include<cmath>
using namespace std ;
int evalpostfix(string s){
    stack<int >st ;
    for (char ch:s){
        if (isdigit(ch)){
            st.push(ch-'0');
        }
        else {
            int val2=st.top();
            st.pop();
            int val1 = st.top();
            st.pop();
         if (ch=='+') st.push( val1 + val2 );
         else if (ch=='-') st.push( val1 - val2 );
         else if (ch=='/') st.push( val1 / val2 );
         else if (ch=='*') st.push( val1 * val2 );
         else if (ch=='^') st.push( pow(val1,val2));
        }
    }
    return st.top();
}
int main(){
    string s ;
    cout<<"enter the postfix expression"<<endl;
    getline(cin,s);
    cout <<"the evaluation of postfix is "<<evalpostfix(s);
return 0;
}