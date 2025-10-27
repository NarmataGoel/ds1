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
      
	}
	
	bool iscircular(){
		 if (last->next== NULL) return false;
    
    node* temp = last->next;
    node* flag = new node(-1);

    while (temp != NULL && temp != flag) {
        node* nextnode = temp->next;
        temp->next = flag;
        temp = nextnode;
    }
    return (temp == flag);
}
	
};
int main(){
	circularlist list ;
	list.insertend(1);
	list.insertend(2);
	list.insertend(3);
	list.insertend(4);
	list.display();
	bool circular = list.iscircular();
	if(circular){
		cout<< "circularlist " ;
	}
	return 0;
}