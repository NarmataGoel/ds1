#include<iostream>
using namespace std ;
struct Listnode{
   int val;
   Listnode *next ;
   Listnode(): val(0), next(nullptr) {}
   Listnode(int x): val(x) , next(nullptr){}
  Listnode(int x, Listnode *next) : val(x), next(next) {}
};
class derived {
  Listnode*head ;
  public :
   derived() { head = nullptr; } 
  void insertbeg(int val ){
   Listnode *newnode=new Listnode(val);
    newnode->next=head ;
    head=newnode;
  }
  void insertend(int val){
    if (!head){
        head=new Listnode(val);
        return ;
    }
    Listnode *temp=head;
    while(  temp && temp->next!=NULL){
    temp=temp->next ;
    }
    temp->next=new Listnode(val);
  }
  void insetbtw(int val,int bef){
    if (!head ){
        cout<<"the head is empty";
    }
    if (head->val == bef) {
        insertbeg(val);
        return;
    }
    Listnode *temp =head ;
    while (temp && temp->next->val!=bef){
     temp=temp->next;
    }
     Listnode *newnode=new Listnode(val);
     newnode->next=temp->next;
     temp->next=newnode ;
  }
  void deletebeg(){
   if (!head ) return ;
   Listnode *temp=head ;
   head=head->next;
   delete temp;
  }
  void deletend(){
    if (!head ) return ;
    Listnode *temp =head ;
    while (temp && temp->next && temp->next->next!=NULL){
        temp=temp->next ;
    }
    temp->next =temp->next->next -+;
  }
  void deletespl(int val){
    if (!head ) return ;
     if (head->val == val)
        {
            head = head->next;
            return;
        }
    Listnode *temp =head ;
    while (temp && temp->next && temp->next->val!=val){
        temp=temp->next;
    }
    temp->next =temp->next->next ;
  }
  int search(int val){
    if (!head) return NULL;
    int i=1;
    Listnode *temp=head;
    while (temp && temp->next->val!= val ){
        temp=temp->next ;
        i++;
    }
   return i;
  }
    void display() {
    if (!head) {
        cout << "No elements in list\n";
        return;
    }
    Listnode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

};

int main(){
    derived ob ;
    bool check =true ;
    while (check){
          int num;
        cout << "1.Insertion at the beginning." << endl;
        cout << "2.Insertion at the end." << endl;
        cout << "3.Insertion in between" << endl;
        cout << "4.Deletion from the beginning." << endl;
        cout << "5.Deletion from the end." << endl;
        cout << "6.Deletion of a specific node" << endl;
        cout << "7.Search for a node" << endl;
        cout << "8.Display all the node values." << endl;
        cout << "9.End the program" << endl;
        int val;
        cin >> num;
       switch(num){
         case 1:
            cout << "Enter the element to insert" << endl;
            cin >> val;
            ob.insertbeg(val);
            break;

        case 2:
            cout << "Enter the element to insert" << endl;
            cin >> val;
            ob.insertend(val);
            break;

        case 3:
            int atval;
            cout << "Enter the element to insert" << endl;
            cin >> val;
            cout << "Enter before which you want to insert" << endl;
            cin >> atval;
            ob.insetbtw(val, atval);
            break;
        case 4:
            ob.deletebeg();
            break;
        case 5:
            ob.deletend();
            break;
        case 6:
            cout << "Enter the element to insert" << endl;
            cin >> val;
            ob.deletespl(val);
            break;
        case 7:
            cout << "Enter the element to insert" << endl;
            cin >> val;
            cout<<"The element is at the position"<<ob.search(val);
            break;
        case 8:
            ob.display();
            break;
        case 9:
            check=false;
            cout<<"The End"<<endl;
            break;

        default:
            cout<<"Please Enter valid number";
            break;
        }
    }
    return 0;
}