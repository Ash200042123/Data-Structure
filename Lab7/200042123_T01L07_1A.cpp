
#include <iostream>
#include<vector>
#include<queue>

using namespace std;

class FindMed {
	priority_queue<int> maxHeap = priority_queue<int>();
	priority_queue<int, vector<int>, greater<int>> minHeap = priority_queue<int, vector<int>, greater<int>>();
	int count = 0;

public:
	void AddNum(int x) {

		if (count % 2 == 0) {
			maxHeap.push(x);
		}
		else {
			minHeap.push(x);
		}
		count++;
		if (!minHeap.empty() && maxHeap.top() > minHeap.top()) {
			int temp1 = minHeap.top();
			int temp2 = maxHeap.top();
			maxHeap.pop();
			maxHeap.push(temp1);
			minHeap.pop();
			minHeap.push(temp2);
		}
	}

	 double FindMedian() {

		if (count % 2 == 0 && !minHeap.empty()) {
			return (double)(maxHeap.top() + minHeap.top()) / 2;
		}
		else {
			return maxHeap.top();
		}
	}
};

int main()
{
	FindMed t;
	t.AddNum(10);
	t.AddNum(12);
	t.AddNum(9);
	cout << t.FindMedian() << endl;
	t.AddNum(8);
	cout << t.FindMedian() << endl;


	return 0;
}

