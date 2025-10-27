#include<iostream>
using namespace std ;
struct Listnode{
   int val;
   Listnode *next ;
   Listnode(): val(0), next(nullptr) {}
   Listnode(int x): val(x) , next(nullptr){}
  Listnode(int x, Listnode *next) : val(x), next(next) {}
};
int func(Listnode *&head ,int n) {
    if (!head) return 0;
    int count = 0;
    while (head && head->val == n) {
        Listnode* del = head;
        head = head->next;
        delete del;
        count++;
    }
    Listnode *temp = head;
    while (temp && temp->next) {
        if (temp->next->val == n) {
            Listnode* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            count++;
        } else {
            temp = temp->next;
        }
    }
    return count;
}
int main(){
    int arr[6] = {1,2,1,3,4,1};
    Listnode *head = new Listnode(arr[0]);
    Listnode *curr = head;  
    for (int i = 1; i < 6; i++) {
        curr->next = new Listnode(arr[i]);
        curr = curr->next;
    }
    cout << "The frequency of 1 is " << func(head, 1) << endl;
    Listnode *temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
