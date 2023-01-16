#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *next;
};

class Stack {
Node *root;
public:
    Stack() {
        root = NULL;
    }

    void push(int new_element);
    int pop();
    int isEmpty();
    int peek();
};

void Stack::push(int new_element) {
    Node* temp = new Node();
    temp->data = new_element;
    if(root == NULL) {
        temp->next = NULL;
    }
    else {
        temp->next = root;
    }
    root = temp;
    cout << root->data << " pushed into the stack\n";
}

int Stack::pop() {
    if(!root) {
        cout << "Stack Underflow!!!\n";
        return 0;
    }
    else {
        Node* temp = root;
        root = root->next;
        int popped_data = temp->data;
        delete(temp);
        return popped_data;
    }
}

int Stack::peek() {
    if(!root) return INT_MIN;
    return root->data;
}

int Stack::isEmpty() {
    return !root;
}

int main() {
    Stack new_stack;
    new_stack.push(5);
    new_stack.push(11);
    new_stack.push(69);
    cout << new_stack.peek() << " is the top element\n";

    cout << new_stack.pop() << " popped out from the stack\n";

    cout << "The elements in the stack are : ";
    while(!new_stack.isEmpty()) {
        cout << new_stack.peek() << " ";
        new_stack.pop();
    }
    cout << "\n";
    cout << new_stack.pop() << " popped out from the stack\n";

    return 0;
}