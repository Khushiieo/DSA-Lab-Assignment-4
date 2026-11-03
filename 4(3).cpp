#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q, temp;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }

    if (n % 2 != 0)
    {
        cout << "Queue must contain an even number of elements";
        return 0;
    }

    int half = n / 2;
    for (int i = 0; i < half; i++)
    {
        temp.push(q.front());
        q.pop();
    }
    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();

        q.push(q.front());
        q.pop();
    }

    cout << "Interleaved queue: ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
