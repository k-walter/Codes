#include <bits/stdc++.h>
using namespace std;

void mergesort(vector<int>& arr, long long int &cnt, int low, int high) {
	if ((high-low) <= 0)
		return;

	int mid = (high + low) / 2;
	mergesort(arr, cnt, low, mid);
	mergesort(arr, cnt, mid+1, high);

	vector<int> arr2;
	arr2.reserve(high - low + 1);
	int left = low;
	int right = mid + 1;

	while (left <= mid && right <= high) { // comparison
		if (arr[left] < arr[right]) {
			arr2.push_back(arr[left++]);
		} else {
			cnt += (right - arr2.size() - low);
			arr2.push_back(arr[right++]);
		}
		// arr2.push_back((arr[left] < arr[right]) ? arr[left++] : arr[right++]);
	}
	while (left <= mid) // add left
		arr2.push_back(arr[left++]);
	while (right <= high) // add right
		arr2.push_back(arr[right++]);

	for (auto &i : arr2)
		arr[low++] = i;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("froshweek.in", "r", stdin);

	int n; cin >> n;
	vector<int> arr(n);
	for (auto &i : arr)
		cin >> i;

	// Mergesort
	long long int cnt = 0;
	mergesort(arr, cnt, 0, arr.size()-1);

	cout << cnt;

	return 0;
}


	// int no = 0;
	// for (int i = 0; i < n-1; ++i)
	// {
	// 	bool swapped = false;
	// 	for (int j = 0; j < n-1-i; ++j)
	// 	{
	// 		if (arr[j] > arr[j+1]) {
	// 			++no;
	// 			swap(arr[j], arr[j+1]);
	// 			swapped = true;
	// 		}
	// 	}
	// 	if (!swapped) break;
	// }
	// // for (auto &i : arr)
	// // 	cout << i << " ";
	// // cout << '\n';

	// cout << no;