/*
You have N boxes in a row and you want to sort them in non-decreasing order of weight from left to right. You also have N choices of small robots that you can use to sort the boxes and 1 battery containing B charges that can ﬁt into any robot.
The i-th robot has a weight of Wi and a cost of Ci. As the robots are small, they are only able to swap 2 neighbouring boxes at one time. Furthermore, if the 2 boxes it swaps have the same weight, or the heavier box is at most Wi times as heavy as the lighter box, then it takes 1 charge of the battery to swap them. Otherwise, it takes 2 charges as it needs to stabilise itself from the unbalanced weight. Moving along the row of boxes does not use up battery charges.
You want to choose 1 robot with the least cost that is able to sort the boxes using at most B charges. Find the cost of this robot. It is guaranteed that at least one of the robots can sort the boxes using at most B charges.
Input
    The ﬁrst line of input contains two integers representing N and B. ThesecondlineofinputcontainsN integersrepresentingtheweightoftheboxesfromlefttoright. The third line of input contains N integers representing W1,W2,...,WN. The fourth line of input contains N integers representing C1,C2,...,CN.
Output
    Your program should output the least cost on a single line.


Name: Walter Kong
Runtime
    T(N) = Θ(NlgN) sort + Θ(N) preprocessing + Θ(lgN) binary search * O(NlgN) sort = O(N lg^2 N)
Description
    Greedily save robots by lower cost. If exists stronger/equal robot with lower cost, take it.
    Binary search possible weights, and stop if robot is overdischarged (REM<0).
    Lower bound of robot weight that is not overdischarged has lowest cost.
*/
#include <bits/stdc++.h>
using namespace std;
int N, B;
long long arr[1<<16], org[1<<16]; // long long to compare W * arr[i]
pair<int,int> WC[1<<16];
deque<tuple<int,int,int>> dq; // FIFO with [] operator, {flag, W, min C}

int i, j, REM, W;
vector<int> tmp;
inline void inv(int l = 0, const int &r = N-1) {
    if (l==r) return;

    // Divide
    int m = (l + r + 1) >> 1;
    inv(l, m-1); // T(N/2)
    if (REM < 0) return;
    inv(m, r); // T(N/2)
    if (REM < 0) return;

    // Count >= inversions
    i = l; j = m;
    while (i<m && j<=r) { // O(N)
        if (arr[i] <= arr[j]) ++i;
        else {
            REM -= m - i;
            if (REM < 0) return;
            ++j;
        }
    }
    // Count > W*right inversions
    i = l; j = m;
    while (i<m && j<=r) { // O(N)
        if (arr[i] <= arr[j] * W) ++i;
        else {
            REM -= m - i;
            if (REM < 0) return;
            ++j;
        }
    }

    // Combine
    i = l; j = m;
    tmp.clear();
    while (i<m && j<=r) // O(N)
        tmp.push_back(arr[i]<=arr[j] ? arr[i++] : arr[j++]);
    while (j <= r) tmp.push_back(arr[j++]); // O(N)
    while (i < m) tmp.push_back(arr[i++]); // O(N)

    // Copy back to original
    for (auto &k : tmp) arr[l++] = k; // O(N)
}
int main(){
    // ios::sync_with_stdio(false); cin.tie(NULL);
    // freopen("sample.in", "r", stdin);
    // freopen("example_test_cases/1.in", "r", stdin);
    // freopen("example_test_cases/2.in", "r", stdin);
    // freopen("example_test_cases/3.in", "r", stdin);
    // freopen("example_test_cases/4.in", "r", stdin);
    freopen("example_test_cases/5.in", "r", stdin);
    // freopen("example_test_cases/6.in", "r", stdin);
    // clock_t st = clock();

    scanf("%d %d", &N, &B);
    for (int i = 0; i < N; ++i) scanf("%d", &org[i]);
    for (int i = 0; i < N; i++) scanf("%d", &WC[i].first);
    for (int i = 0; i < N; i++) scanf("%d", &WC[i].second);

	// write your code here

    // Initialise flag, remove duplicate weight, save running min cost
    // ie dq[i] = {flag, W, min C}
    sort(WC, WC+N); // O(nlgn)
    for (int i = N-1; i >= 0; --i) { // O(N)
        // Highest weight, strongest robot
        if (dq.empty())
            dq.emplace_front(-1, WC[i].first, WC[i].second);
        // Lower weight, min_cost(current robot, stronger robot)
        else if (get<1>(dq.front()) != WC[i].first)
            dq.emplace_front(-1, WC[i].first, min(get<2>(dq.front()), WC[i].second));
        // Same weight, take lower cost
        else
            get<2>(dq.front()) = min(get<2>(dq.front()), WC[i].second);
    }

    // Binary Search answer
    int r = dq.size() - 1;
    for (int l = 0, m; l != r;) { // T(k)
        m = (l + r) >> 1;

        // Try current weight
        int &flag = get<0>(dq[m]);
        if (flag == -1) {
            // Copy unsorted array
            for (int i = 0; i < N; ++i) arr[i] = org[i]; // Θ(N)
            // Initialise weight, charges
            W = get<1>(dq[m]);
            REM = B;
            // Sort
            inv(); // O(N lg N)
            // Set overdischarged, prevent retrying current weight
            flag = REM >= 0;
        }

        // KIV current, look for lower weights (and costs)
        if (flag) r = m; // T(k/2)
        // Overdischarged, try stronger robot
        else l = m + 1; // T(k/2)
    }
    // Lower bound of working robots has lowest cost
    printf("%d\n", get<2>(dq[r]));

    // printf("CPU time used: %lf ms\n", 1000.0 * (clock()-st) / CLOCKS_PER_SEC);
	return 0;
}
