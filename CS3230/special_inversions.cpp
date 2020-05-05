/*
Given an array arr[] containing N integers, two elements arr[i] and arr[j] form an inversion if i < j and arr[i] > arr[j]. We call the inversion special if arr[i]+arr[j] is a multiple of P. Write a program to count the number of special inversions in the array
Input
	The ﬁrst line of input contains two integers representing N and P. The second line of input contains N integers representing the array arr[].
Output
	Your program should output the number ofspecialinversions on a single line.


Name: Walter Kong
Runtime
	T(n) = 2*T(n/2) + O(n) = Θ(n log n)
Description
	In each subroutine, initialise a frequency table of possible special inversions.
	Eg 25' = (25%12)' = 1' = 11
	During merge part of merge sort, either left subarray or right subarray is appended. Let x be the current item to be added from left or right subarray.
		1. If x from right subarray, save special inversion of x to be considered for items>x in left subarray.
		2. If x from left subarray, increment answer by #special inversions from right subarray.
*/
#include <bits/stdc++.h>
using namespace std;
int N, P;
int arr[1<<16];
long long answer = 0; // 2^16_C_2 > INT_MAX

int i, j;
int VIS_TOK = -1; // max = 2P = 2^21 < INT_MAX
vector<int> tmp; // non in-place mergesort
int cnt[1<<20], vis[1<<20]; // count special inversions
// bitset<1<<20> vis; // fast "cnt" reset indicator
inline void solve(int l = 0, const int &r = N - 1) {
	if (l == r) return;

	// Divide
	int m = (l + r + 1) >> 1;
	solve(l, m-1); // T(n/2)
	solve(m, r); // T(n/2)

	// Combine
	i = l; j = m;
	tmp.clear();
	++VIS_TOK; // Θ(1)
	while (i<m && j<=r) { // O(n)
		// Increment special inversions
		if (arr[i] <= arr[j]) {
			const int &k = arr[i] % P;
			// Visited special inversion on right subarray?
			if (vis[k] == VIS_TOK) answer += cnt[k]; // Θ(1)
			tmp.push_back(arr[i++]);
		}
		// Save possible special inversions
		else { // left > right
			const int &k = P - (arr[j]-1) % P - 1;
			// First time visiting special inversion in this subroutine
			if (vis[k] != VIS_TOK) {
				vis[k] = VIS_TOK;
				cnt[k] = 0;
			}
			++cnt[k]; // Θ(1)
			tmp.push_back(arr[j++]);
		}
	}
	// No new inversions
	while (j <= r) tmp.push_back(arr[j++]); // O(n)
	while (i < m) { // O(n)
		const int &k = arr[i] % P;
		if (vis[k] == VIS_TOK) answer += cnt[k];
		tmp.push_back(arr[i++]);
	}

	// Copy back to original
	for (auto &k : tmp) arr[l++] = k; // O(n)
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("sample.in", "r", stdin);
	// freopen("example_test_cases/1.in", "r", stdin);
	// freopen("example_test_cases/2.in", "r", stdin);
	// freopen("example_test_cases/3.in", "r", stdin);
	// freopen("example_test_cases/4.in", "r", stdin);
	// freopen("example_test_cases/5.in", "r", stdin);
	// freopen("example_test_cases/6.in", "r", stdin);
	// freopen("example_test_cases/7.in", "r", stdin);
	// clock_t st = clock();

    scanf("%d %d", &N, &P);
    for (int i = 0; i < N; ++i) scanf("%d", &arr[i]);
	
	// write your code here
    memset(vis, VIS_TOK, P*sizeof(int));
    solve();
    printf("%d\n", answer);

    // printf("CPU time used: %lf ms\n", 1000.0 * (clock()-st) / CLOCKS_PER_SEC);
	return 0;
}