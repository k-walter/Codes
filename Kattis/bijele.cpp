#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("bijele.in", "r", stdin);

	int n; int arr[]={1,1,2,2,2,8};
	for (int i = 0; i < 6; ++i) {
		cin>>n; cout << arr[i]-n << " ";
	}

	return 0;
}