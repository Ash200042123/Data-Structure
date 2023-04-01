
#include <iostream>
#include<queue>


using namespace std;

int main()
{
	queue<int> x;
	queue<int> y;
	int k,k_copy=0;
	int dummy;
	int count = 0,f=0;

	while (1) {
		cin >> dummy;
		if (dummy == -1) break;
		x.push(dummy);
	}
	cin >> k;

	while (f!=1) {
		while (!x.empty()) {
			int s = x.front();
			
			s--;
			count++;

			if (k_copy == k && s == 0) {
				f = 1;
				break;
			}

			else if (s == 0 && k_copy != k) {
				x.pop();
				k_copy++;
				if (k > k_copy) k--;
				continue;
			}

			y.push(s);
			x.pop();
			k_copy++;
		}
		x = y;
		k_copy = 0;
		while (!y.empty()) {
			y.pop();
		}
	}
	
	cout << count;
	return 0;
}

