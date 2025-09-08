#include <iostream>
#include<string>
using namespace std;

struct stack {
    int m=100;        
    char s1[100];      
    int t = -1;   

    bool isfull() {
        return (t == m - 1);
    }

    bool isempty() {
        return (t == -1);
    }

    void push(int x) {
        if (isfull()) {
            cout << "Stack overflow!" << endl;
        } else {
            t++;
            s1[t] = x;
        }
    }

    char pop() {
        if (isempty()) {
            cout << "Stack underflow!" << endl;
        } else {
            cout<<s1[t];
          t--;
        }
    }
};

int main(){
    cout<<"enter the string "<<endl;
    string s="";
    cin>>s;
stack st ;
for(int i=0;i<s.size();i++){
    st.push((s[i]));
}
cout<<"reverse string "<<endl ;
 while (!st.isempty()) {
        st.pop();
    }
    cout<<endl;

return 0;
}