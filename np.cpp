
int minSetCover(int u, int mask) {
	if (mask == 0) { return 0; }
	int ans = 1e9;
	while (mask) {
		int d = LSOne(mask);
		mask -= d;
		int v = __builtin_ctzl(d);
		if (v < u) continue;
		ans = min(ans, minSetCover(v, mask & ~am[v]));
	}
	return ++ans;
}


inline bool ok(int mask) {
	auto &ans = okm[mask];
	if (okv[mask] == VIS) return ans;
	okv[mask] = VIS; ans = 1;
	while (mask) {
		int u = LSOne(mask);
		mask -= u;
		for (int v,m = mask; m; m -= v) {
			v = LSOne(m);
			if (am[__builtin_ctzl(u)] & v) continue;
			return ans = 0;
		}
	}
	return 1;
}

inline int minCliqueCover(int mask, int depth) {
	if (mask == 0) { return 0; }
	if (depth >= hi) return hi;
	int &ans = dp[mask];
	if (vis[mask] == VIS) return ans;
	ans = hi; vis[mask] = VIS;
	for (int ss = mask; ss; ss = (ss-1) & mask) {
		if (!ok(ss)) continue;
		ans = min(ans, minCliqueCover(mask & ~ss, depth + 1) + 1);
	}
	// cout<<bitset<16>(mask)<<" " << ans<<"\n";
	return ans;
}

