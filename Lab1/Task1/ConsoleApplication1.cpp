
#include <iostream>
#include<vector>
#include<map>
#include<array>
#include<algorithm>
using namespace std;

int main()
{
	int t[100000];
	int occ[10] = { 0 };
	int i=0;

	while (1) {
		cin >> t[i];
		if (t[i] <= 0) {
			break;
		}
		occ[t[i]]++;
		i++;
	}
	int j = 1;
	//sort(occ, occ+10);
	while (j < 10) {
		if (occ[j] > 0) {
			cout << j << " occurs: " << occ[j] << " times" << endl;
		}
		j++;
	}
	
	return 0;
}

