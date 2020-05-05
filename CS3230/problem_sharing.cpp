/*
Alice and Bob are learning a module namedDesignandAnalysisofAlgorithms. They are given a set of 2N problems for their programming assignment. Since output of the previous problem is input of the next problem, the problems must be solved in a strict order. Formally, for every 1 ≤ i < 2N, problem i must be solved before problem i + 1. Their parents know the friends very well, so they can estimate that for the i-th problem (1 ≤ i ≤ 2N), Bob will solve it in b[i] minutes while it takes Alice a[i] minutes to do the same. Bob and Alice want to cooperate to solve all the problems, each will solve N of them (for maintaining a good relationship). Luckily, their parents agree with the plan, but they are not smart enough to distribute the problems in such a way that minimizes total number of minutes for Bob and Alice to solve all problems. And they know that you are very smart! Please help them to ﬁnd a way to distribute problems in such a way that all problems can be solved in minimum number of minutes.
Input
	The ﬁrst line contains a positive integer N. Next 2N lines, the i-th line contains two positive integers a[i] and b[i].
Output
	A single line contains the smallest number of minutes for Bob and Alice to solve all problems

Name: Walter Kong
Describe your algorithm and explain your time complexity here:
	Assuming Bob did all 2N problems, Alice greedily selects N problems such that total time is reduced.
	Θ(n) + O(nlgn) + Θ(n)
	= O(n + nlgn + n)
	= O(nlgn)
Prove the correctness of your algorithm here:
	1. For each problem i, let c_i = a_i - b_i be the tradeoff for Alice to do the problem in lieu of Bob. i.e. c_i < 0 means that Alice takes less time on problem i than Bob.
	2. Partition 2N problems such that for i = [1,N], j = [N+1, 2N], c_j >= c_i
	3. Suppose algorithm returning t' is non-optimal, ie exists optimal solution t such that t' > t
		3.1 To arrive at the optimal solution, Alice must choose k problems from j = [N+1, 2N] to replace k problems from i = [1,N] such that t' + (c_{j,1} - c_{i,1}) + ... + (c_{j,k} - c_{i,k}) = t
		3.2 0 > t - t' (from 3.)
			= (c_{j,1} - c_{i,1}) + ... + (c_{j,k} - c_{i,k})
		3.3 Since any c_j >= c_i, c_j - c_i >= 0 (from 2.)
		3.4 (c_{j,1} - c_{i,1}) + ... + (c_{j,k} - c_{i,k}) >= 0 * k
			= 0
			< 0 (contradiction)
	4. Therefore t' <= t.
		4.1 Since t is the optimal solution, any solution t' >= t.
		4.2 Therefore t' = t, algorithm returns optimal solution.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("sample_tests/0.in", "r", stdin);
	// freopen("sample_tests/1.in", "r", stdin);
	// freopen("sample_tests/2.in", "r", stdin);
	// freopen("sample_tests/3.in", "r", stdin);
	// freopen("sample_tests/4.in", "r", stdin);
	// freopen("sample_tests/5.in", "r", stdin);
	// freopen("sample_tests/6.in", "r", stdin);
	// clock_t st = clock();

	int n, a, b;
	scanf("%d", &n);
	vector<int> v;
	long long ans = 0;

	// Time for Bob to do 2N problems
	for (int i = 0; i < (n<<1); ++i) { // Θ(n)
		scanf("%d%d", &a, &b);
		ans += b;
		v.push_back(a - b);
	}

	// Alice greedily selects N problems with less tradeoff
	nth_element(v.begin(), v.begin() + n, v.end()); // O(nlgn)
	while (n--) ans += v[n]; // Θ(n)

	printf("%lld\n", ans);
    // printf("CPU time used: %lf ms\n", 1000.0 * (clock()-st) / CLOCKS_PER_SEC);
	return 0;
}