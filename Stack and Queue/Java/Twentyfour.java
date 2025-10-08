class MyCircularQueue {
    private int arr[];

    private int front = 0, rear = 0, size = 0, count = 0;

    public MyCircularQueue(int k) {
        arr = new int[k];
        front = 0;
        rear = -1;
        size = k;
        count = 0;
    }

    public boolean enQueue(int value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % size;
        arr[rear] = value;
        ++count;
        return true;
    }

    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % size;
        --count;
        return true;
    }

    public int Front() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    public int Rear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    public boolean isEmpty() {
        return count == 0;
    }

    public boolean isFull() {
        return count == size;
    }
}

public class Twentyfour {
    public static void main(String[] args) {

    }
}
