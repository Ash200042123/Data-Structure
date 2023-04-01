
#include <iostream>
#include<vector>
#include<map>
#include <sstream>

using namespace std;

int p = 31;
const int N = 507, m = 407;
vector<long long> power(N);


int main()
{
	string x = "", y = "";
	int i, j;
	int f = 1;

	cin >> x;
	cin >> y;

	i = x.size();
	j = y.size();

	power[0] = 1;

	for (int k = 1;k < N;k++) {
		power[k] = (power[k - 1] * p) % m;
	}

	vector<long long> h(i + 1, 0);

	for (int k = 0;k < i;k++) {
		h[k + 1] = (h[k] + (x[k] - 'a' + 1) * power[k]) % m;
	}

	long long h_s = 0;
	for (int k = 0;k < j;k++) {
		h_s = (h_s + (y[k] - 'a' + 1) * power[k]) % m;
	}

	for (int k = 0;k + j - 1 < i;k++) {
		long long ans = (h[k + j] - h[k] + m) % m;

		if (ans == (h_s * power[k]) % m) {
			cout << k << " ";
			f = 0;
		}
	}
	if (f == 1) cout << "-1";

	return 0;
}

