#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int,int> node;
vector<int> arr;
inline node solve(int l = 0, const int &r = arr.size()-1) {
	// printf("%d %d\n", l,r);
	if (l == r) return {arr[l], arr[l], arr[l], arr[l]}; // pre, suf, tot
	const auto &[la,lp,ls,lt] = solve(l, (l+r)>>1);
	const auto &[ra,rp,rs,rt] = solve(((l+r)>>1)+1, r);
	return {max({la, ra, ls+rp}), max(lp, lt+rp), max(rs, ls+rt), ls+rt};
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen(".in", "r", stdin);

	arr = {-2, -5, 6, -2, -3, 1, 5, -6};
	const auto &[a,_,__,___] = solve();
	printf("%d\n", a);
	return 0;
}