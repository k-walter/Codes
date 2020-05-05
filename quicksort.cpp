#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int>& arr, int low, int high) {
	if (low >= high)
		return;

	// select pivot
	int r = low + rand() % (high - low + 1);
	int p = arr[r];
	swap(arr[r], arr[low]);

	// partition
	int mid = low + 1;
	for (int i = low + 1; i <= high; ++i)
		if (arr[i] < p || (arr[i] == p && rand() % 2)) // 50% for equal
			swap(arr[mid++], arr[i]);
	swap(arr[low], arr[mid-1]); // place pivot

	// sort partition
	quicksort(arr, low, mid-2); // sort <
	quicksort(arr, mid, high); // sort >
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("arr.in", "r", stdin);

	int n; cin >> n;
	vector<int> arr(n);
	for (auto &i : arr)
		cin >> i;

	for (auto &i : arr)
		cout << i << " ";
	cout << "\n";

	quicksort(arr, 0, arr.size()-1);

	for (auto &i : arr)
		cout << i << " ";

	return 0;
}