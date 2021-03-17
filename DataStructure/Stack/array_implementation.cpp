#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack
{
    int top;

public:
    int a[MAX];
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top == MAX - 1)
    {
        cout << "Error: Overflow happened." << endl;
        return 0;
    }
    else
    {
        a[++top] = x;
        return 1;
    }
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else
    {
        top--;
        return 1;
    }
}

int Stack::peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty." << endl;
        return -1;
    }
    else
    {
        return a[top];
    }
}

bool Stack::isEmpty()
{
    return (top == -1);
}

int main()
{
    class Stack s;
    s.push(10);
    cout << s.peek() << endl;
    s.push(20);
    cout << s.peek() << endl;
    s.push(30);
    cout << s.peek() << endl;

    cout << s.pop() << " Popped from stack\n";

    return 0;
}