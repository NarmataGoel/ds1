#include <iostream>
using namespace std;

struct dnode {
    char data;
    dnode* prev;
    dnode* next;
    dnode(char val) {
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

    void insertatend(char val) {
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

    bool ispalindrome() {
        if (head == NULL || head->next == NULL)
            return true;

        dnode* left = head;
        dnode* right = head;
        while (right->next != NULL){
		
            right = right->next;
        }

        while (left != right && left->prev != right) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    void display() {
        dnode* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    doublylinkedlist list;
    string str;

    list.insertatend('a');
        list.insertatend('b');
            list.insertatend('c');
                list.insertatend('b');
                    list.insertatend('a');

    cout << "List: ";
    list.display();

    if (list.ispalindrome())
        cout << "The doubly linked list is a palindrome.\n";
    else
        cout << "The doubly linked list is not a palindrome.\n";

    return 0;
}
