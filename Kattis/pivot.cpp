#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("pivot.in", "r", stdin);

	int n; cin >> n;
	vector<long long int> arr;
	arr.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		long long int j; cin >> j;
		arr.push_back(j);
	}

	// Running max
	vector<bool> maxs(n, false);
	long long int max = arr[0]-1;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > max) {
			maxs[i] = true;
			max = arr[i];
		}
	}

	// Running min
	int cnt = 0;
	long long int min = arr[n-1]+1;
	for (int i = n - 1; i >= 0; --i)
	{
		if (arr[i] < min) {
			min = arr[i];
			if (maxs[i])
				++cnt;
		}
	}
	cout << cnt;

	return 0;
}

	// DOESN'T WORK BECAUSE
	// Even if correct position, other values are not = it's not pivot
	// vector<long long int> sorted(arr);
	// sort(sorted.begin(), sorted.end());

	// int cnt = 0;
	// for (int i = 0; i < n; ++i)
	// {
	// 	if (arr[i] == sorted[i]) {
	// 		++cnt;
	// 	}
	// }