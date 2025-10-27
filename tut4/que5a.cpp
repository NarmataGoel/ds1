#include<iostream>
#include<queue>
using namespace std;

class Stack {
    queue<int> q1, q2;
    int n = 0;
public:
    void push(int x) {
        q1.push(x);
        n++;
    }
    void pop() {
        if (q1.empty()) {
            cout << "No element in stack" << endl;
            return;
        }
        for (int i = 1; i < n; i++) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        n--;
        swap(q1, q2);
    }

    int peek() {
        if (q1.empty()) {
            cout << "No peak element in stack" << endl;
            return -1;
        }

        int val = -1;
        for (int i = 1; i <= n; i++) {
            val = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        return val;
    }
};

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    Stack q;

    for (int i = 0; i < 5; i++) {
        q.push(arr[i]);
    }

    cout << "Top element: " << q.peek() << endl; 
    q.pop();
    cout << "Top after pop: " << q.peek() << endl; 
    q.push(7);
    cout<<q.peek();
    return 0;
}
