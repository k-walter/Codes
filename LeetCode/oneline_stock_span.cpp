#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
class SegmentTree {
private:
	int n;
	vi st, lazy;
	inline int l(int p) { return p<<1; }
	inline int r(int p) { return l(p)+1; }
	int conquer(int a, int b) {
		if (a == -1) return b;
		if (b == -1) return a;
		return max(a, b); // comparator
	}

	void build(int p, int L, int R, const vi &A) {
		if (L == R) st[p] = A[L]; // leaf
		else {
			int m = (L + R) >> 1;
			build(l(p), L, m, A);
			build(r(p), m+1, R, A);
			st[p] = conquer(st[l(p)], st[r(p)]);
		}
	}

	void propagate(int p, int L, int R) {
		if (lazy[p] == -1) return; // not lazy
		st[p] = lazy[p]; // update segment
		if (L != R) lazy[l(p)] = lazy[r(p)] = lazy[p]; // update subsegment
		lazy[p] = -1;
	}

	int RMQ(int p, int L, int R, int i, int j) {
		propagate(p, L, R);
		if (i > j) return -1;
		if (i<=L && R<=j) return st[p];
		int m = (L + R) >> 1;
		return conquer(RMQ(l(p), L, m, i, min(j,m)),
					   RMQ(r(p), m+1, R, max(m+1,i), j));
	}

	void update(int p, int L, int R, int i, int j, int val) {
		propagate(p, L, R);
		if (i > j) return;
		if (i<=L && R<=j) { // within segment
			lazy[p] = val;
			propagate(p, L, R);
		} else {
			int m = (L + R) >> 1;
			update(l(p), L, m, i, min(j,m), val);
			update(r(p), m+1, R, max(i,m+1), j, val);
			int lseg = (lazy[l(p)] == -1) ? st[l(p)] : lazy[l(p)];
			int rseg = (lazy[r(p)] == -1) ? st[r(p)] : lazy[r(p)];
			st[p] = (lseg >= rseg) ? st[l(p)] : st[r(p)];
		}
	}
public:
	SegmentTree(int _n) : n(_n), st(n<<2, -1), lazy(n<<2, -1) {}
	SegmentTree(const vi &A) : SegmentTree(A.size()) { build(1, 0, n-1, A); }
	void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }
	void update(int i, int val) { update(i, i, val); }
	int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
	int RMQ(int i) { return RMQ(min(n-1,i), n-1); }
};

class StockSpanner {
public:
	int lo = INT_MAX;
	map<int,int> m;
	SegmentTree st = SegmentTree(1e5+1);
	int it = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
    	st.update(price, it);
    	printf("max %d ", st.RMQ(price+1));
    	return it++ - st.RMQ(price+1);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen(".in", "r", stdin);


	StockSpanner s;
	vector<int> A = {100,80,60,70,60,75,85};
	for (int &i : A) {
		printf("%d\n", s.next(i));
	}
}