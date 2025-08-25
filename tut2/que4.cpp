#include<iostream>
using namespace std ;
// 4a
string concetenate(string s1,string s2){
    string result=s1+s2;
     return result ;
}
//   4b
   string reverse(string s,int n){
    string result ="";
    for (int i=n-1;i>=0;i--){
      result.push_back(s[i]);
    }
return result;
   }
   // 4c
   void dltvowels(string s,int n){
     string result="";
     for (char ch:s){
        if (ch!='u'&& ch!='a'&& ch!='e'&& ch!='i'&&ch!='o' ){
            result.push_back(ch);
        }
     }
     cout<<"the string without vowel is "<<result;
   }
int main(){
  string s1="hello ";
  string s2="world";
   string  s3=concetenate(s1,s2);
   cout<<s3;
   int n=s1.size();
    string rev=reverse(s1,n);
    cout<<endl<<"reverse of "<<s1<< "is"<<rev<<endl;
   dltvowels(s1,n);
return 0;
}