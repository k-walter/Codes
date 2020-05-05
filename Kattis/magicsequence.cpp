#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;

// b >= 31623 for 2 rounds (since maxima is 73,391)
#define B2 10 // original (15) is slower for reasons
const int B = 1 << B2;
const int MAX = log(1e9)/log(B) + 1; // no rounds based on max val
const int MOD = B - 1;
bool first;
int arr[1000000], arr2[1000000];
int bucket[B];
// int* radixSort() {
void radixSort() {
	first = true;
	int high = 0;

	for (int _i = 0; _i < MAX; ++_i) {
		const auto &ARR1 = (first ? arr : arr2);
		auto &ARR2 = (first ? arr2 : arr);
		first = !first;

		// Count
		memset(&bucket, 0, sizeof(bucket));
		for (int i = 0; i < n; ++i)
			++bucket[(ARR1[i] >> high) & MOD];

		// Position / Prefix sum array
		for (int i = 1; i < B; ++i)
			bucket[i] += bucket[i-1]; // saves idx(last item)+1

		// Move
		for (int i = n-1; i >= 0; --i) // copying backwards = stable
			ARR2[--bucket[(ARR1[i] >> high) & MOD]] = ARR1[i];

		// LSD
		high += B2;
	}
	// return first ? arr : arr2;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("magicsequence.in", "r", stdin);

	int tc; cin>>tc;
	while (tc--) {
		int a,b,c,x,y; cin>>n>>a>>b>>c>>x>>y;
		b%=c; x%=y;
		
		arr[0] = a; a%=c;
		for (int i = 1; i < n; ++i)
			arr[i] = ((ll)arr[i-1] * b + a) % c;
		
		// const auto &s = radixSort();
		radixSort();
		const auto &s = first ? arr : arr2;
		// for (int i = 0; i < n; ++i)
		// 	cout << s[i] << " ";
		// cout << "\n";

		ll v = 0;
		for (int i = 0; i < n; ++i)
			v = (v * x + s[i]) % y;
		cout << v << "\n";
		// cout << "\n";
	}

	return 0;
}