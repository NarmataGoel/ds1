#include<iostream>
using namespace std ;
int main(){
string s="HELLO";
int n=s.size();
for (int i=0;i<n;i++){
    s[i]=s[i]+32;
}
cout<<s;

return 0;
}