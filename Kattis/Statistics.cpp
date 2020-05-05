#include <cstdio>

int main_c(){
	freopen("Statistics.in", "r", stdin);

	int case_no = 0;
	int foo;
	int no, min, max;

	while(scanf("%d", &foo) != EOF) {
		min = 1000001;
		max = -1000001;
		while(foo--) {
			scanf("%d", &no);
			if(no < min) {
				min = no;
			}
			if(no > max) {
				max = no;
			}
		}
		printf("Case %d: %d %d %d\n", ++case_no, min, max, max-min);
	}
	return 0;
}

// #include <iostream>
// #include <algorithm>
#include <bits/stdc++.h> // includes everything
using namespace std;
int main() {
	int caseNo = 0, n;
	while(cin>>n, !cin.eof()) { // computes in order, return last comma
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		// int min = *min_element(arr, arr+n);
		auto [min, max] = minmax_element(arr, arr+n); // return addr
	}
}
// int main() {
// 	freopen("Statistics.in", "r", stdin);

// 	int n, caseNo=0;
// 	while(scanf("%d", &n) != EOF) {

// 		int min = 1e9; //10^9
// 		int max = -1e9;
// 		for (int i = 0; i < n; ++i)
// 		{
// 			int val;
// 			scanf("%d", &val);
// 			if (val < min)
// 				min = val;
// 			if (val > max)
// 				max = val;
// 		}
// 		printf("Case %d: %d %d %d\n", ++caseNo, min, max, max-min);
// 	}

// 	return 0;
// }