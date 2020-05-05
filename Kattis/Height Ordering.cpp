#include <bits/stdc++.h>
using namespace std;

// Can insert while sorting!!!
int InsertionSort(int arr[]) {
	int swaps = 0;
	for (int i=1; i<20; ++i) {
		int j = i;
		while (j-- && (arr[j] > arr[j+1])) { // break when sorted
			// int tmp = arr[j];
			// arr[j] = arr[j+1];
			// arr[j+1] = tmp;
			swap(arr[j], arr[j+1]);
			++swaps;
		}
	}
	return swaps;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("Height Ordering.in", "r", stdin);

	int n; cin >> n;
	while (n--) {
		int k; cin >> k;
		cout << k << " ";

		int arr[20];
		int swaps = 0;
		for (int i = 0; i < 20; ++i) {
			cin >> arr[i];

			int j = i;
			while (j-- && (arr[j] > arr[j+1])) {
				swap(arr[j], arr[j+1]);
				++swaps;
			}
		}
		cout << swaps << endl;
		// cout << k << " " << InsertionSort(arr) << endl;
	}

	return 0;
}