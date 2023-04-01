
#include <iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	priority_queue<int> stones;
	int i = 0;

	while (1) {
		int n;
		cin >> n;

		if (n == -1) {
			break;
		}

		stones.push(n);
		i++;
	}

	while (stones.size() > 1) {
		int first = stones.top();
		stones.pop();

		int second = stones.top();
		stones.pop();

		int diff = first - second;

		if (diff > 0)
		{
			stones.push(diff);
		}
		else {
			stones.push(0);
		}
	}

	//while(stones.size() > 2) {
	//	int first = stones.top();
	//	stones.pop();

	//	int second = stones.top();
	//	stones.pop();

	//	int diff = first-second;

	//	if (diff > 0) 
	//	{ 
	//		stones.push(diff);
	//	}
	//}

	//if (stones.size() == 2)
	//{
	//	int first = stones.top();
	//	stones.pop();

	//	int second = stones.top();
	//	stones.pop();

	//	if (first != second)
	//	{
	//		int diff = first - second;
	//		stones.push(diff);
	//	}
	//	else {
	//		stones.push(0);
	//	}
	//}

	cout << stones.top() << endl;
	return 0;
}

