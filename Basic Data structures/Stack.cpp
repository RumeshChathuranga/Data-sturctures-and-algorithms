#include <iostream>
#include <vector>
using namespace std;

class Stack {
    // <--- ADD YOUR CODE HERE --->
    private:
    vector<int> arr; // Using a vector to store stack elements
    int size;

    public:
    // Constructor to initialize the stack with a given size
    Stack(int size) {
        this->size = size;
    }
    // Push operation
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow";
        } else {
            arr.push_back(x);  // Adding element to the vector
        }
    }
    
    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow";
        } else {
            arr.pop_back();  // Removing the top element from the vector
        }
    }


    // Check if the stack is empty
    bool isEmpty() {
        return arr.empty();
    }

    // Check if the stack is full
    bool isFull() {
        int length = arr.size();
        return length == size;
    }
    

    // Get the top element
    int stackTop() {
        if (!isEmpty()) {
            return arr.back();  // Return the last element in the vector
        } else {
            cout<<"Stack Underflow";
            return 0;
        }
    }

    // Display the elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack Underflow";
        } else {
            for (int i = arr.size() - 1; i >= 0; --i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack myStack(5);
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
        } else if (instruction == "isFull") {
            if (myStack.isFull()) std::cout << "True\n";
            else std::cout << "False\n";
        } else if (instruction == "stackTop"){
            myStack.stackTop();
        } else if (instruction == "exit") {
            break;
        } else {
            std::cout << "Invalid instruction. Valid instructions: push, pop, display, exit.\n";
        }
    }

    return 0;
}