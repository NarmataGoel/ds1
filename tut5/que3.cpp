#include<iostream>
using namespace std ;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  void display(ListNode * rev){
    while(rev!=NULL){
    cout<<rev->val<<" " ;
   rev = rev->next ;
    ;}
  }
int main(){
    ListNode* head = new ListNode( 1);
    head->next =  new ListNode( 2);
     head->next->next =  new ListNode( 3);
     
     int size=0;
     ListNode* temp = head ;
   while(head!=NULL){
   size++;
   head= head->next ;
}
for(int i=0;i<size/2;i++){
    temp=temp->next;
}
cout<<temp->val;
return 0;
}