#include <iostream>
#include <exception>

using namespace std;

class QueueOverflowException : public exception
{
};
class QueueUnderflowException : public exception
{
};

template <typename T>
class Queue
{
private:
    T *data;
    int front, rear, count, capacity;

public:
    Queue(int cap) : capacity(cap), front(0), rear(-1), count(0)
    {
        data = new T[capacity];
    }

    ~Queue()
    {
        delete[] data;
    }

    void enqueue(T item)
    {
        if (isFull())
        {
            throw QueueOverflowException();
        }
        rear = (rear + 1) % capacity;
        data[rear] = item;
        count++;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            throw QueueUnderflowException();
        }
        T item = data[front];
        front = (front + 1) % capacity;
        count--;
        return item;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == capacity;
    }

    int size()
    {
        return count;
    }
};

int main()
{
    Queue<int> q(2);

    try
    {
        cout << "Attempting to enqueue to a full queue ..." << endl;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
    }
    catch (const QueueOverflowException &e)
    {
        cerr << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    try
    {
        cout << "\nDequeuing all elements..." << endl;
        q.dequeue();
        q.dequeue();
        cout << "\nAttempting to dequeue from an empty queue ..." << endl;
        q.dequeue();
    }
    catch (const QueueUnderflowException &e)
    {
        cerr << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
