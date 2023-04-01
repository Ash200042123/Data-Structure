#include<iostream>
using namespace std;

class Queue
{
private:
    int Front, Rear;
    int Size;
    int* arr;

public:

    Queue(int s)
    {
        Front = Rear = -1;
        Size = s;

        arr = new int[s];
    }

    void enQueue(int val)
    {

        if (Front == 0 && Rear == Size - 1)
        {
            cout << "No Space" << endl;
        }

        else if (Front == -1)
        {
            Front = Rear = 0;
            arr[Rear] = val;
        }

        else
        {
            Rear++;
            arr[Rear] = val;
        }

    }
    int deQueue()
    {

        if (Front == -1)
        {
            cout << "EMPTY" << endl;
            return -1;
        }

        int data = arr[Front];
        arr[Front] = -1;

        if (Front == Rear)
        {
            Front = Rear = -1;
        }

        else
        {
            Front++;
        }
        return data;

    }

    int GetSize()
    {
        return Size;
    }
    int GetFront()
    {
        return arr[Front];
    }
    int GetRear()
    {
        return arr[Rear];
    }
    bool isEmpty()
    {
        if (Front == -1)
            return true;

        else
            return false;
    }
    bool isFull()
    {
        if (Front == 0 && Rear == Size - 1)
            return true;

        else
            return false;
    }

    void displayQueue()
    {
        if (Front == -1)
        {
            cout << "EMPTY" << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = Front; i <= Rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};







int main()
{
    Queue q(4);

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);

    q.displayQueue();

    cout << "Is it Full: " << q.isFull() << "   " << "Is it Empty: " << q.isEmpty() << endl;
    cout << "Front element: " << q.GetFront() << "   Rear element: " << q.GetRear() << endl;
    cout << "Size: " << q.GetSize() << endl;
    cout << "Popping: " << q.deQueue() << endl;
    cout << "Popping: " << q.deQueue() << endl;

    q.displayQueue();
}




