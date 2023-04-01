#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    int n, moves, ans;
    cin >> n >> moves;

    queue<int> friends;

    for (int i = 1; i <= n; i++)
    {
        friends.push(i);
    }

    while (!friends.empty())
    {
        for (int i = 1; i < moves; i++)
        {
            int temp = friends.front();
            friends.pop();
            friends.push(temp);
        }

        ans = friends.front();
        friends.pop();
    }

    cout << ans << endl;

    return 0;
}
