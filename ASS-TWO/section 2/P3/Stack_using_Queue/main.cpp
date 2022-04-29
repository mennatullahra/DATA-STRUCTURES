#include <iostream>

#define MAX 100
int top, state;
using namespace std;

template<class T>
class Queue {
    int size;
    T *queue;

public:
    Queue() {
        size = 0;
        queue = new T[100];
    }

    Queue(T value, int intial_size) {

    }

    ~Queue() {

    }

    T &front() {
        return queue[0];
    }

    void pop() {
        if (size == 0) {
            cout << "Stack_using_Queue is empty" << endl;
            return;
        } else {
            for (int i = 0; i < size - 1; i++) {
                queue[i] = queue[i + 1];
            }
            size--;
        }
    }

    void push(T data) {
        queue[size] = data;
        size++;
    }

    int getsize() {
        return size;
    }

    bool empty() {
        if (size == 0) {
            return true;
        } else return false;
    }
};

class Stack {
    Queue<int> q1, q2;
    int curr_size;
public:
    Stack() {
        curr_size = 0;
    }

    int top() {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    void pop() {
        if (q1.empty())
            return;
        q1.pop();
        curr_size--;
    }

    void push(int x) {
        curr_size++;
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        Queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout<<s.top()<<endl;
    return 0;

    return 0;
}