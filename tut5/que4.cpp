#include<iostream>
using namespace std ;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  ListNode* reverse(ListNode* head ){
    ListNode* prev=NULL;
    ListNode* temp = head ;
    while (temp!=NULL){
        ListNode* next1=temp->next;
        temp->next=prev ;
        prev = temp ;
        temp= next1;
    }
    return prev ;
  }
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
// cout <<head->val<<head->next->val;
  ListNode *rev = reverse(head );
   display (rev);
return 0;
}