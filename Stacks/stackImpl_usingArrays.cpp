/*........ Implementation of stacks, stacks can be implemented in two ways:
 1. using array
 2. using linked list

what is stack?
A stack is a linear data structure where operatios are performed in certain order.

To implement the stack, it is required to maintain the pointer to the top of the stack, which is the last element to be inserted because we can access the elements only on the top of the stack.

it follows LIFO (Last in first out) or FILO (first in last out) .......*/

//implemenatation using arrays


#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
#define MAX 1000
 
class Stack {
    int top;

    public:
        int new_stack[MAX];

        Stack() { top = -1; }
        bool push(int new_element);
        int pop();
        int peek();
        bool isEmpty();
};    

bool Stack::push(int new_element) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow\n";
        return false;
    }
    else {
        new_stack[++top] = new_element;
        cout << new_element << " pushed into the stack!!!\n";
        return true;
    }
}

int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return 0;
    }
    else {
        int pop_element = new_stack[top--];
        return pop_element;
    }
}

int Stack::peek() {
    if (top < 0) {
        cout << "Stack is empty\n";
        return 0;
    }
    else {
        int top_element = new_stack[top];
        return top_element;
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    class Stack s;
    s.push(5);
    s.push(11);
    s.push(69);
    cout << s.pop() << " Popped from stack\n";

    cout << "Elements present in stack : ";
    while(!s.isEmpty()) {
        cout << s.peek() << " ";
        s.pop();
    }

    return 0;
}

/* using array isn't recommended as the size should be defined earlier and we can't shrink or grow the stack */