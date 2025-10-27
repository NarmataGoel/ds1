#include <iostream>
using namespace std;

struct dnode {
    int data;
    dnode* prev;
    dnode* next;
    dnode(int val) {
        data = val;
        prev = next = NULL;
    }
};

class doublylinkedlist {
private:
    dnode* head;

public:
    doublylinkedlist() {
        head = NULL;
    }

int size(){
	dnode* temp = head ;
	int size =0 ;
	while(temp!= NULL){
		size++;
		temp = temp->next ;
	}
	return size ;
}
    void insertatbeginning(int val) {
        dnode* newnode = new dnode(val);
        newnode->next = head;
        if (head != NULL) head->prev = newnode;
        head = newnode;
    }

    void insertatend(int val) {
        dnode* newnode = new dnode(val);
        if (head == NULL) {
            head = newnode;
            return;
        }
        dnode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
        newnode->prev = temp;
    }

    void insertafter(int after, int val) {
        dnode* temp = head;
        while (temp != NULL && temp->data != after)
            temp = temp->next;
        if (temp == NULL) {
            cout << "node not found.\n";
            return;
        }
        dnode* newnode = new dnode(val);
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newnode;
        temp->next = newnode;
    }

    void deletenode(int val) {
        if (head == NULL) {
            cout << "list is empty.\n";
            return;
        }

        dnode* temp = head;
        while (temp != NULL && temp->data != val)
            temp = temp->next;

        if (temp == NULL) {
            cout << "node not found.\n";
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "node " << val << " deleted.\n";
    }

    void searchnode(int val) {
        dnode* temp = head;
        int pos = 1;
        while (temp != NULL) {
            if (temp->data == val) {
                cout << "node " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "node not found.\n";
    }

    void display() {
        dnode* temp = head;
        cout << "doubly linked list: ";
        while (temp != NULL) {
            cout << temp->data ;
            temp = temp->next;
        }
        cout << "null\n";
    }
};

int main(){
	doublylinkedlist list ;
	list.insertatend(1);
	list.insertatend(2);
	list.insertatend(3);
	list.insertatend(4);
	list.insertatend(5);
	int size = list.size();
	cout << "size is :" << size << endl;
	
	list.display();
}