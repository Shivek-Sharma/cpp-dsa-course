// Implementation of Doubly Ended Queue (deque) using array
// https://www.codingninjas.com/studio/problems/deque_1170059

#include <bits/stdc++.h>
class Deque
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // if queue is full
        if (isFull())
        {
            return false;
        }

        // first element to insert
        if (isEmpty())
        {
            front = rear = 0;
        }
        // to maintain cyclic nature
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        // normal flow
        else
        {
            front--;
        }

        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // if queue is full
        if (isFull())
        {
            return false;
        }

        // first element to insert
        if (isEmpty())
        {
            front = rear = 0;
        }
        // to maintain cyclic nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        // normal flow
        else
        {
            rear++;
        }

        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // if queue is empty
        if (isEmpty())
        {
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        // if single element present
        if (front == rear)
        {
            front = rear = -1;
        }
        // to maintain cyclic nature
        else if (front == size - 1)
        {
            front = 0;
        }
        // normal flow
        else
        {
            front++;
        }

        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // if queue is empty
        if (isEmpty())
        {
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        // if single element present
        if (front == rear)
        {
            front = rear = -1;
        }
        // to maintain cyclic nature
        else if (rear == 0)
        {
            rear = size - 1;
        }
        // normal flow
        else
        {
            rear--;
        }

        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[rear];
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};