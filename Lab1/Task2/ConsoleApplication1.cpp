
#include <iostream>
#include<vector>
#include<map>

using namespace std;

long calcFactorial(int n) {
	if (n == 0) {
		return 1;
	}
	return n * calcFactorial(n - 1);
}
int main()
{
	int t;
	cin >> t;

	cout << calcFactorial(t) << endl;
	return 0;
}

