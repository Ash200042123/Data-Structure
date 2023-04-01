
#include <iostream>

using namespace std;

void swap(int* x, int* y) {

	int temp = *y;
	*y = *x;
	*x = temp;
}

void print(int arr[], int n) {

	for (int i = 0;i < n;i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void heapify(int arr[], int n, int i) {

	//Finding the largest
	int largest = i;
	int left = (2 * i) + 1;
	int right = (2 * i) + 2;

	if (left<n && arr[left]>arr[largest]) {
		largest = left;
	}
	if (right<n && arr[right]>arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void Build_max_heap(int arr[], int n) {

	//Building max heap
	for (int i = n / 2 - 1;i >= 0;i--) {
		heapify(arr, n, i);
	}
}

void heapSort(int arr[], int n) {

	Build_max_heap(arr, n);

	for (int i = n - 1;i >= 0;i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}

}


void deleteRoot(int arr[], int n)
{
	int last = arr[n - 1];
	arr[0] = last;    
	n--;          

	heapify(arr, n, 0);
}



int Heap_Minim(int heap[]) {
	return heap[0];
}

int Heap_extract_min(int arr[], int n)
{
	int ans = arr[0];
	deleteRoot(arr, n);      
	return ans;
}


void Min_heap_insert(int x, int arr[], int n)
{
	n++;
	arr[n - 1] = x;     
	Build_max_heap(arr, n);       
}



int main()
{
	int a[1000];

	int i = 0;
	while (1) {
		int x;
		cin >> x;
		if (x == -1) break;
		a[i] = x;
		i++;
	}
	
	cout << Heap_Minim(a)<<endl;

	Build_max_heap(a, i);
	print(a,i);

	cout << Heap_extract_min(a, i) << endl;

	Min_heap_insert(35, a, i);
	i++;
	print(a, i);

	return 0;
}

