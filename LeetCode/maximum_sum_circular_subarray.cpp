#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	Solution() { ios::sync_with_stdio(false); cin.tie(NULL); }
    int maxSubarraySumCircular(vector<int>& A) {
    	if (A.size() == 1) return A[0];
    	int n = A.size(), anslo = A[0], ans = A[0], hi = A[0], lo = A[0], sum = A[0];
    	for (int i = 1; i < n; ++i) {
    		hi = (hi <= 0) ? A[i] : hi+A[i];
    		ans = max(ans, hi);
    		lo = (lo >= 0) ? A[i] : lo+A[i];
    		anslo = min(anslo, lo);
    		sum += A[i];
    	}
    	return max(ans, sum-anslo);
    }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen(".in", "r", stdin);

	Solution s;
	vector<int> A = {5,-3,5}; 
	printf("%d", s.maxSubarraySumCircular(A));

	return 0;
	int ans = A[0], kad = A[0];
	for (int &i : A) {
		kad = (kad <= 0) ? i : i+kad;
		ans = max(ans, kad);
		printf("%d %d %d\n", i, kad, ans);
	}
	return 0;
}
