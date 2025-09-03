/**
 * @file stack_with_array.cpp
 * @brief A simple implementation of a stack data structure using a fixed-size array.
 */

#include <iostream>

#define MAX_SIZE 100

using namespace std;

/**
 * @class stack
 * @brief Implements a LIFO (Last-In, First-Out) stack using an array.
 *
 * This class provides basic stack operations like push, pop, peek,
 * and checks for whether the stack is empty or full. The stack has a
 * fixed capacity defined by MAX_SIZE.
 */
class stack {
private:
    int _stack_container[MAX_SIZE]; ///< Array to store stack elements.
    int _stack_pointer;             ///< Index of the top element of the stack.

public:
    /**
     * @brief Constructs a new, empty stack.
     */
    stack() 
    {
        _stack_pointer = -1;
    }

    /**
     * @brief Checks if the stack is empty.
     * @return True if the stack is empty, false otherwise.
     */
    bool is_empty() 
    {
        return _stack_pointer == -1;
    }

    /**
     * @brief Checks if the stack is full.
     * @return True if the stack has reached its maximum capacity, false otherwise.
     */
    bool is_full()
    {
        return _stack_pointer == MAX_SIZE - 1;
    }

    /**
     * @brief Pushes an integer onto the top of the stack.
     * @param num The integer to be pushed onto the stack.
     * If the stack is full, an error message is printed and the operation is aborted.
     */
    void push(int num) 
    {
        if (is_full()) 
        {
            cerr << "Error: Stack is full." << endl;
            return;
        }
        _stack_container[++_stack_pointer] = num;
    }

    /**
     * @brief Removes and returns the top element of the stack.
     * @return The element at the top of the stack.
     * If the stack is empty, an error message is printed and -1 is returned.
     */
    int pop()
    {
        if (is_empty()) 
        {
            cerr << "Error: Stack is empty." << endl;
            return -1; // Return a sentinel value
        }
        return _stack_container[_stack_pointer--];
    }

    /**
     * @brief Returns the top element of the stack without removing it.
     * @return The element at the top of the stack.
     * If the stack is empty, an error message is printed and -1 is returned.
     */
    int peek()
    {
        if (is_empty())
        {
            cerr << "Error: Stack is empty." << endl;
            return -1; // Return a sentinel value
        }
        return _stack_container[_stack_pointer];
    }

    /**
     * @brief Displays all the elements in the stack from bottom to top.
     *
     * If the stack is empty, an error message is printed.
     */
    void display()
    {
        if (is_empty())
        {
            cerr << "Error: Stack is empty." << endl;
            return;
        }
        for (int i = 0; i <= _stack_pointer; i++)
        {   
            cout << _stack_container[i] << " ";
        }
        cout << endl;
    }
};

/**
 * @brief Main function to demonstrate the stack functionality.
 */
int main() {
    stack my_stack;
    //my_stack.push(10);
    //my_stack.push(20);
    /*cout << "Top element is: " << my_stack.peek() << endl;
    cout << "Popped element is: " << my_stack.pop() << endl;
    cout << "Top element is: " << my_stack.peek() << endl;
    */
    my_stack.display();
    return 0;
}
