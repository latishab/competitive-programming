#include <iostream>

/*
1. Peek(), we access the first element of the array
2. Pop(), we do 'queue[i] = queue[i+1]' then decrement the topIndex
3. Push(), we simply push and increment the topIndex
*/

class MyQueue {
private:
    int topIndex;
    int *queue;
    int capacity;

    void resize(int newCapacity) {
        // allocate a new queue
        int *newQueue = new int[newCapacity];

        // copy to a new queue
        for (int i=0; i <= topIndex; i++) {
            newQueue[i] = queue[i];
        }

        // delete the old queue
        delete [] queue;

        queue = newQueue;
        capacity = newCapacity;
    }

public:
    MyQueue(): topIndex(-1), capacity(4) {
        queue = new int[capacity];
    }

    ~MyQueue() {
        delete [] queue;
    }
    
    void push(int x) {
        if (topIndex == capacity - 1) {
            resize (2 * capacity);
        }
        queue[++topIndex]=x;
    }
    
    int pop() {
        // if the queue is empty, hence return.
        if (topIndex < 0) {
            return -1; // Queue is empty
        }
        int val = queue[0];
        for (int i=0; i < topIndex; i++) {
            queue[i] = queue[i + 1];
        }
        --topIndex;
        return val;
    }
    
    int peek() {
        // if the queue is empty, hence return.
        if (topIndex < 0) {
            return -1; // Queue is empty
        }
        return queue[0]; // we return the first element
    }
    
    bool empty() {
        return topIndex < 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
