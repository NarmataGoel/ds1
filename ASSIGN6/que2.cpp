#include<iostream>
using namespace std ;
struct node{
	int data ;
	node* next ;
	node(int val){
		next = NULL ;
		data = val ;
	}
};

class circularlist{
private:
node* last ;
public :
	circularlist(){
		last = NULL ;
	}
	

	
	void insertend(int val){
		node* newnode = new node(val);
		if(last==NULL){
			last = newnode ;
		newnode->next = last ;	
		}
		else{
			newnode->next = last->next ;
			last->next = newnode ;
			last = newnode ;
		}
	}
	

	

	

	
	void display(){
		  node* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data ;
            temp = temp->next;
        } while (temp != last->next);
        cout << last->next->data ;
	}
};
int main(){
	circularlist list ;
	list.insertend(1);
	list.insertend(2);
	list.insertend(3);
	list.insertend(4);
	list.display();
	return 0;
}