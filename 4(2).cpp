#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue
{
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % SIZE == front;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full\n";
            return;
        }

        if (isEmpty())
            front = 0;

        rear = (rear + 1) % SIZE;
        arr[rear] = value;

        cout << value << " inserted\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Deleted element: " << arr[front] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Front element: " << arr[front] << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue elements: ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    int choice, value;

    do
    {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check isEmpty\n";
        cout << "4. Check isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                if (q.isEmpty())
                    cout << "Queue is Empty\n";
                else
                    cout << "Queue is Not Empty\n";
                break;

            case 4:
                if (q.isFull())
                    cout << "Queue is Full\n";
                else
                    cout << "Queue is Not Full\n";
                break;

            case 5:
                q.display();
                break;

            case 6:
                q.peek();
                break;

            case 7:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}
