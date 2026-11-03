#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q;

public:
    void push(int x)
    {
        int n = q.size();
        q.push(x);

        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top()
    {
        if (q.empty())
            cout << "Stack is Empty\n";
        else
            cout << "Top: " << q.front() << endl;
    }

    void display()
    {
        queue<int> temp = q;

        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main()
{
    Stack s;
    int choice, x;

    do
    {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cin >> x;
                s.push(x);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.top();
                break;

            case 4:
                s.display();
                break;
        }

    } while (choice != 5);

    return 0;
}
