#include <iostream>
#include <vector>
using namespace std;
class MyCircularQueue
{
private:
    vector<int> q;
    int front, rear, size, count;

public:
    MyCircularQueue(int k)
    {
        q.resize(k, 0);
        front = 0;
        rear = -1;
        size = k;
        count = 0;
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        rear = (rear + 1) % size;
        q[rear] = value;
        ++count;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }
        front = (front + 1) % size;
        --count;
        return true;
    }

    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return q[front];
    }

    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return q[rear];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == size;
    }
};
int main()
{
    MyCircularQueue q(3);
    cout << q.enQueue(1) << "\n";
    cout << q.enQueue(2) << "\n";
    cout << q.enQueue(3) << "\n";
    cout << q.enQueue(4) << "\n";
    cout << q.Rear() << "\n";
    cout << q.isFull() << "\n";
    cout << q.deQueue() << "\n";
    cout << q.enQueue(4) << "\n";
    cout << q.Rear() << "\n";
    return 0;
}
