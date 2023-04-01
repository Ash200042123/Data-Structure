#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    int n, q, s, ans = 0;
    cin >> n;

    int arr[n];
    queue<int> line;
    stack<int> sandwich;

    for (int i = 0; i < n; i++)
    {
        cin >> q;
        line.push(q);
    }


    for (int i = 0; i < n; i++)
    {
        cin >> s;
        arr[i] = s;
    }

    for (int i = (n - 1); i >= 0; i--)
    {
        sandwich.push(arr[i]);
    }


    for (int i = 0; i < (n * 2); i++)
    {
        if (line.front() == sandwich.top())
        {
            ans++;
            line.pop();
            sandwich.pop();
        }

        else
        {
            int temp = line.front();
            line.pop();
            line.push(temp);
        }
    }


    cout << n - ans << endl;

    return 0;
}
