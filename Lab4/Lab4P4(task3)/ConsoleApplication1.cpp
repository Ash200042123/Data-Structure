#include<iostream>
#include<queue>
using namespace std;

queue<int> line;

void push_s(int x)
{
    int Size = line.size();

    line.push(x);

    for (int i = 0; i < Size; i++)
    {
        int temp = line.front();
        line.push(temp);
        line.pop();
    }

}

void pop_s()
{
    line.pop();
}

int top_s()
{
    return line.front();
}

bool empty_s()
{
    return line.empty();
}

int main()
{
    push_s(1);
    cout << top_s() << endl;

    push_s(2);
    cout << top_s() << endl;

    pop_s();
    cout << top_s() << endl;

    push_s(3);
    cout << top_s() << endl;
    cout << empty_s() << endl;

    pop_s();
    pop_s();

    cout << empty_s() << endl;

    return 0;
}
