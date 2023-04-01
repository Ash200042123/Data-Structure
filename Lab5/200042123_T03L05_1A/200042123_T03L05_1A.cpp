
#include <iostream>
#include<queue>


using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> q;

    int n, k;
    int operations = 0;

    cin >> n >> k;

    while(n)
    {
        int x;
        cin >> x;
        q.push(x);
        n--;
    }

    int first, second, y;

    while (q.size() > 1)
    {
        if (q.top() >= k)
        {
        break;
        }
        else if(q.top()<k)
        {
            first = q.top();
            q.pop();
            second = q.top();
            q.pop();

            y = (first * 1) + (second * 2);
            q.push(y);

            operations++;
        }

    }
    cout << operations << endl;
    return 0;
}


