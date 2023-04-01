
#include <iostream>
#include<vector>
#include<map>
#include <sstream>

using namespace std;

int p = 31;
const int N = 1e5 + 7, m = 1e9 + 7;
vector<long long> power(N);


int main()
{
	vector<int> x;
	int y;
	int i, j;
	int f = 1;
	while (1) {
		int n;
		cin >> n;

		if (n == -1) { break; }

		x.push_back(n);
	}

	cin >> y;
	i = x.size();
	j = sizeof(y);
	power[0] = 1;

	for (int k = 1;k < N;k++) {
		power[k] = (power[k - 1] * p) % m;
	}

	vector<long long> h(i + 1, 0);

	for (int k = 0;k < i;k++) {
		h[k + 1] = (h[k] + (x[k] - '1' + 1) * power[k]) % m;
	}

	long long h_s = 0;
	for (int k = 0;k < j;k++) {
		h_s = (h_s + (y - '1' + 1) * power[k]) % m;
	}
	
	for (int k = 0;k< i;k++) {
		long long ans = (h[k + j] - h[k] + m) % m;

		if (ans == (h_s * power[k]) % m) {
			cout << "yes";
			f = 0;
			break;
		}
	}
	if (f == 1) cout << "NO\n";

	return 0;
}

