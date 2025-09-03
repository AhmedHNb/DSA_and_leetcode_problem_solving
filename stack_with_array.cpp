#include <iostream>

#define MAX_SIZE 100

using namespace std;

class stack {
private:
    int _stack_container[MAX_SIZE];
    int _stack_pointer;

public:
    stack() 
    {
        _stack_pointer = -1;
    }

    bool is_empty() 
    {
        return _stack_pointer == -1;
    }

    bool is_full()
    {
        return _stack_pointer == MAX_SIZE - 1;
    }

    void push(int num) 
    {
        if (is_full()) 
        {
            cerr << "Error: Stack is full." << endl;
            return;
        }
        _stack_container[++_stack_pointer] = num;
    }

    int pop()
    {
        if (is_empty()) 
        {
            cerr << "Error: Stack is empty." << endl;
            return -1; // Return a sentinel value
        }
        return _stack_container[_stack_pointer--];
    }

    int peek()
    {
        if (is_empty())
        {
            cerr << "Error: Stack is empty." << endl;
            return -1; // Return a sentinel value
        }
        return _stack_container[_stack_pointer];
    }

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
