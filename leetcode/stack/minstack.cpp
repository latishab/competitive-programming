#include <iostream>

using namespace std;

/*
1. Create two stacks: one to keep track of the minimum value, one to 
   keep the elements in order
2. getMin shouldn't remove any element from the stack
3. Only pop() that is able to remove an element from the stack
*/
class MinStack {
private:
    int topIndex;
    int *stack;
    int *minStack; // Create an auxiliary stack to keep track of the minimum
    int capacity;

    // Resize the stack to new capacity
    void resize (int newCapacity) {
        int *newStack = new int[newCapacity];
        int *newMinStack = new int[newCapacity];

        for (int i=0; i <= topIndex; i++) {
            newStack[i] = stack[i];
            newMinStack[i] = minStack[i];
        }

        delete [] stack;
        delete [] minStack;

        stack = newStack;
        minStack = newMinStack;
        capacity = newCapacity;
    }

public:
    // Define a constructor
    MinStack() {
        capacity = 4; // Start small
        stack = new int[capacity];
        minStack = new int[capacity];
        topIndex = -1;
    }
    
    // Define a destructor
    ~MinStack() {
        delete [] stack;
        delete [] minStack;
    }

    void push(int val) {
        // Check if the stack is full?
        if (topIndex == capacity-1) {
            // Stack is full, resize it
            resize (2 * capacity);
        }
        ++topIndex;
        stack[topIndex] = val;

        if (topIndex == 0) {
            minStack[topIndex] = val;
        } else {
            minStack[topIndex] = min(minStack[topIndex-1], val);
        }
    }
    
    void pop() {
        // Check if the stack is empty?
        if (topIndex < 0) {
            // Stack underflow
            return;
        }
        --topIndex;
    }
    
    int top() {
        if (topIndex < 0) {
            return -1;
        }
        return stack[topIndex];
    }
    
    int getMin() {
        if (topIndex < 0) {
            return -1;
        }
        return minStack[topIndex];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
