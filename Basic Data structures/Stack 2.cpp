#include <iostream>
#include <vector>
using namespace std;

class Node {
    // <--- ADD YOUR CODE HERE --->
    public:
    int data;
    Node* next;

    // Constructor to initialize the node
    Node(int data) {
        this->data = data;
        this->next = NULL;  // Set the next pointer to NULL
    }

};

class Stack {
    // <--- ADD YOUR CODE HERE --->
    private:
    Node* top;  // Pointer to the top of the stack

    public:
    // Constructor to initialize the stack
    Stack() {
        top = NULL;  // Set the stack to be empty initially
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == NULL; 
    }

    // Method to push a value onto the stack
    void push(int data) {
        Node* newNode = new Node(data);  // Create a new node

        if (isEmpty()) {
            top = newNode;  // If stack is empty, the new node is the top
        } else {
            newNode->next = top;  // The new node points to the current top
            top = newNode;  // The new node becomes the new top
        }
    }

    // Method to pop a value from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Error: Stack Underflow\n";  // Stack is empty
        } else {
            Node* temp = top;  // Store the current top node
            top = top->next;  // Move the top pointer to the next node
            delete temp;  // Delete the old top node
        }
    }

    // Method to display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";  // If stack is empty
        } else {
            Node* current = top;  // Start from the top node
            while (current != NULL) {
                cout << current->data << " ";  // Print the data
                current = current->next;  // Move to the next node
            }
            cout << "\n";
        }
    }

    // Method to return the top element of the stack
    int stackTop() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;  // Return -1 if stack is empty
        }
        return top->data;  // Return the data of the top node
    }
};

int main() {
    Stack myStack;
    std::string instruction;

    while (true) {
        std::cin >> instruction;

        if (instruction == "push") {
            int data;
            std::cin >> data;
            myStack.push(data);
        } else if (instruction == "pop") {
            myStack.pop();
        } else if (instruction == "display") {
            myStack.display();
        } else if (instruction == "isEmpty") {
            if (myStack.isEmpty()) std::cout << "True\n";
            else std::cout << "False\n";
        } else if (instruction == "stackTop") {
            std::cout << myStack.stackTop() << "\n";
        } else if (instruction == "exit") {
            break;
        } else {
            std::cout << "Invalid instruction. Valid instructions: push, pop, display, exit.\n";
        }
    }

    return 0;
}