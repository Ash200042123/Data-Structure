
#include <iostream>
#include<vector>
#include<map>

using namespace std;

void binarySearchIterative(vector<int> a, int find,int s) {
	int low = 0;
	int high = s ;
	//cout << high << endl;
	int f = 0;
	while (low != high) {
		int mid = (low + high) / 2;
		if (find==a[mid]) {
			cout << mid << endl;
			f = 1;
			break;
		}
		else if (find > a[mid]) {
			low = mid+1;
		}
		else if (find < a[mid]) {
			high = mid-1;
		}
	}
	if (f == 0) {
		cout << "-1" << endl;
	}
}


int binarySearchRecursive(vector<int> a,int find,int low,int high) {

	int f = 0;
	if (high >=1 ) {
		int mid = (low + (high-1)) / 2;
		if (find == a[mid]) {
			cout << mid << endl;
			f = 1;
			return mid;
		}
		else if (find > a[mid]) {
			return binarySearchRecursive(a, find, mid + 1, high);
		}
		else if (find < a[mid]) {
			return binarySearchRecursive(a, find, low, mid - 1);
		}
	}
	
	return -1;
	
}
int main()
{
	int t=0;
	vector<int> a;
	int to_find;

	while (1) {
		int x;
		cin >> x;
		if (x < 0) {
			break;
		}
		a.push_back(x);
		
	}
	cin >> to_find;
	int n = a.size() - 1;
	binarySearchIterative(a, to_find,n);
	//cout << binarySearchRecursive(a, to_find, 0, n) << endl;
	return 0;
}

