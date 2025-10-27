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
	
	int size(){
		node* temp = last->next ;
		int size = 1 ;
		while(temp!=last){
			size++;
			temp = temp->next ;
		}
		return size ;
	}
	void insertbegin(int val){
		node* newnode = new node(val);
		if(last==NULL){
			last = newnode ;
		newnode->next = last ;	
		}
		else{
			newnode->next = last->next ;
			last->next = newnode ;
		}
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
	
	void insertafter(int val , int after){
		node* temp = last->next ;
		do{
		 if (temp->data == after) {
                node* newnode = new node(val);
                newnode->next = temp->next;
                temp->next = newnode;
                if (temp == last) last = newnode;
                return;
            }
            temp = temp->next;	
		}while(temp != last->next);
	}
	
	void deletenode(int val){
		 node* curr = last->next;
        node* prev = last;

        do {
            if (curr->data == val) {
                if (curr == last && curr == last->next) {
                    last = NULL;
                } else {
                    prev->next = curr->next;
                    if (curr == last) last = prev;
                }
                delete curr;
                cout << "Node " << val << " deleted.\n";
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != last->next);
	}
	
	void search(int val){
		 node* temp = last->next;
        int pos = 1;
        do {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << "\n";
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next);
	}
	
	void display(){
		  node* temp = last->next;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data ;
            temp = temp->next;
        } while (temp != last->next);
	}
};
int main(){
	circularlist list ;
	list.insertend(1);
	list.insertend(2);
	list.insertend(3);
	list.insertend(4);
	int size = list.size();
	cout << "size is :" << size << endl ;
	list.display();
	return 0;
}