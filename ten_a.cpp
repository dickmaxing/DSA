#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    // Add an element to the end of the queue
    void enqueue(int x) {
        s1.push(x);
    }

    // Remove an element from the front of the queue
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        // Move elements from s1 to s2 if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << endl;
        s2.pop();
    }

    // Get the front element of the queue
    void front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        // Move elements from s1 to s2 if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.front();
    cout << "\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
}
