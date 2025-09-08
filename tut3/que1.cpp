#include <iostream>
using namespace std;

struct stack {
    int m=100;        
    int s[100];      
    int t = -1;   

    bool isfull() {
        return (t == m - 1);
    }

    bool isempty() {
        return (t == -1);
    }

    void push(int x) {
        if (isfull()) {
            cout << "Stack overflow!" << endl;
        } else {
            t++;
            s[t] = x;
        }
    }

    void pop() {
        if (isempty()) {
            cout << "Stack underflow!" << endl;
        } else {
            cout << "Deleted element: " << s[t] << endl;
            t--;
        }
    }

    void peek() {
        if (isempty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Top element: " << s[t] << endl;
        }
    }

    void display() {
        if (isempty()) {
            cout << "Stack is empty!" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= t; i++) {
                cout << s[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    bool right = true;
    stack st;
    while (right) {
        cout << "\nSelect operation:\n";
        cout << "1. Push (insert)\n";
        cout << "2. Pop (delete)\n";
        cout << "3. Peek (top element)\n";
        cout << "4. Check isEmpty\n";
        cout << "5. Check isFull\n";
        cout << "6. Display stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";

        int x;
        cin >> x;

        switch (x) {
            case 1: {
                int num;
                cout << "Enter the number: ";
                cin >> num;
                st.push(num);
                break;
            }
            case 2:
                st.pop();
                break;
            case 3:
                st.peek();
                break;
            case 4:
                if (st.isempty())
                    cout << "Stack is empty\n";
                else
                    cout << "Stack is not empty\n";
                break;
            case 5:
                if (st.isfull())
                    cout << "Stack is full\n";
                else
                    cout << "Stack is not full\n";
                break;
            case 6:
                st.display();
                break;
            case 7:
                right = false;
                cout << "Program ended.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
