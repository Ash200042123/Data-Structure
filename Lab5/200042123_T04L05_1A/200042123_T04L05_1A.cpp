
#include <iostream>
#include<queue>
#include<map>

using namespace std;

int main()
{
	int n;
	priority_queue<int> start_time;
	priority_queue<int> end_time;
	int rooms = 0;

	cin >> n;

	int n1 = n;
	while (n) {
		int x, y;
		cin >> x;
		start_time.push(x);

		cin >> y;
		end_time.push(y);
		n--;
	}

	while (n1) {
		if (start_time.top() < end_time.top()) {
			rooms++;
			end_time.pop();
		}
		else {
			break;
		}
		n1--;
	}
	cout << rooms << endl;
	return 0;
}

