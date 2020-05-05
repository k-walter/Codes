#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int PASS = -1e9;

/*
Alice have a pack of N + 1 identical balloons. She took one balloon and blow M + 1 cm3 of air into it and the balloon pop. Being curious, she wants to ﬁnd the elastic score of those balloons(same for all balloons), deﬁne as the largest integer amount of air x in cm3 such that a balloon can contain that amount of air without being pop. Note that, the elastic score of those balloons must be a non-negative integer less than or equal to M. In order to do that, she will conduct trials. Each trial involve blowing x cm3 of air into a balloon (1 ≤ x ≤ M)andeithertheballoonpopornot. Iftheballoonpop,itcannotbeusedinlatertrials. Being lazy, she wants to know the answer with the least trials. You are her good friend so she ask you to ﬁnd out the number of trials needed in the worst case.
Input
	A single line contains two integers representing N and M.
Output
	A single number represent the number of trials needed.
Limits
	• 1 ≤ N ≤ 100,1 ≤ M ≤109
	• Your program should terminate within 1 second for C++11 and 2 seconds for Java 

Describe your algorithm and explain your time complexity here.
	Represent the problem as a binary tree, such that
		Each trial = internal nodes
		Each elastic score = leaf nodes
		Popped option = left subtree
		Non-popped option = right subtree
		#Trials = max depth
	We binary search the lower bound of #trials by checking #elastic score (#leaves) given a binary tree of max depth (#trials) >= actual range of values (m + 1)
		ie T(n ballons, x trials) >= m + 1
	To check, we use top-down dynamic programming on T(n balloons left, x depth left)
		Base Case
			T(0,x) = 1 // n=0 balloons left, must have 1 possible elastic score
			T(n,0) = 1 // max depth reached, must have 1 possible elastic score
			T(>=x,x) = 2^x // n=#balloons > x=depth left, full binary tree of depth x possible -> 2^x leaves
		General Case
			T(n,x) = #elastic scores if balloon pops + #elastic scores if balloon is fine
			= T(n-1,x-1) + T(n,x-1) since 1 less trial
	Optimisations
		For n=1, #trails=m, we can save memory (and speed) by returning m
		For n>=2, m<=1e9, max x at n=2
			Since more balloons = less "linear search"
			Then m <= (x + x-1 + ... + 1) + 1 = x(x+1)/2 + 1
			Which gives x_min = 44721
			Thus, initialise memo[n+1][x_min+1]
		For m<=1e9, max #trials = 1e9 + 1
			Then (subtree #leaves > 1e9 + 1) AND (subtree #leaves <= T(n,x) #leaves) -> (T(n,x) #leaves > 1e9 + 1)
				We know original #trials is more than sufficient
			Also addition of (x >= 30) -> (#leaves >= 2^30 > 1e9+1) may cause int32 to overflow
			Thus, flag when it happens and replace with arbitrary -ve number.
	Time Complexity
		Let m' = min(44721, m+1)
		Θ(n * m') + Θ(lg m') + O(n * m') // Since we memoize previous answers
		= O(n * m')
*/

///You can declare global variables in case you need it.
bool flag;
int memo[101][44722]; // max T(2,1e9) = 44721

inline int bt(const int &n, const int &x) { // O(n * m')
	// only 1 possible leaf left
	if (n == 0 || x == 0) return 1; // Θ(1)
	// (#lefts >= depth) -> Full binary tree
	if (n >= x) {
		// 2^x
		if (x < 30) return (1 << x); // Θ(1)
		// Since x_max = 1e9, prevents overflow
		flag = 1;
		return PASS; // Θ(1)
	}

	// memoization
	int &ans = memo[n][x];
	if (ans != -1) { // Θ(1)
		if (ans == PASS) flag = 1;
		return ans;
	}

	// right
	ans = bt(n, x-1);
	if (ans > INF) flag = 1;
	if (flag) return ans = PASS;

	// left
	ans += bt(n-1, x-1);
	if (ans > INF) flag = 1;
	if (flag) ans = PASS;
	return ans;
}

inline int solve(const int &n, int m) {
	// To use less memory
	if (n == 1) return m;

	// Binary Search #leaves
	int L = 1, R = min(++m, 44721), x;
	while (L < R) { // O(lg m')
		x = (L + R) >> 1;
		flag = 0;
		if (bt(n, x) >= m || flag) R = x;
		else L = x + 1;
	}

	return L;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("input/0.in", "r", stdin);
	// freopen("input/1.in", "r", stdin);
	// freopen("input/2.in", "r", stdin);
	// freopen("input/3.in", "r", stdin);
	// freopen("input/4.in", "r", stdin);
	// freopen("input/5.in", "r", stdin);
	// freopen("input/6.in", "r", stdin);
	// freopen("input/7.in", "r", stdin);
	// freopen("input/8.in", "r", stdin);
	// freopen("input/9.in", "r", stdin);
	freopen("input/10.in", "r", stdin);
	clock_t st = clock();

	int n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i <= n; ++i) // Θ(n * m')
		for (int j = 0; j <= min(m+1, 44721); ++j)
			memo[i][j] = -1;
	printf("%d", solve(n, m));

    printf("\nCPU time used: %lf ms\n", 1000.0 * (clock()-st) / CLOCKS_PER_SEC);
	return 0;
}