#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class StackNode {
    public:
     int data;
     StackNode* next;
};

StackNode* newNode(int data) {
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(StackNode* root) {
    return !root;
}

void push(StackNode** root, int data) {
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " pushed to stack\n";
}

int pop(StackNode** root) {
    if (isEmpty(*root)) return INT_MIN;

    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(StackNode* root) {
    if(isEmpty(root)) return INT_MIN;
    return root->data;
}

int main() {
    StackNode *root = NULL;

    push(&root,5);
    push(&root,11);
    push(&root,69);
    push(&root,17);

    cout << pop(&root) << "Popped from stack\n";
    cout << "Top element is " << peek(root) << endl;

    cout << "Elements present in the stack : ";
    while(!isEmpty(root)) {
        cout << peek(root) << " ";
        pop(&root);
    }
    return 0;
}