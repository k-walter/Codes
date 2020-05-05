#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("gearchanging.in", "r", stdin);

	int n,m,p; cin >> n >> m >> p;
	p += 100;
	// double p; cin >> p;
	// p /= 100;

	vector<int> front, back;
	front.reserve(n);
	back.reserve(m);
	while (n--) {
		int i; cin >> i;
		front.push_back(i);
	}
	while (m--) {
		int i; cin >> i;
		back.push_back(i);
	}


	using ll = pair<long long int,long long int>;
	// typedef pair<long long int,long long int> ll; // same as above
	vector<ll> ratio;
	for (auto &i : front) {
		for (auto &j : back) {
			ratio.emplace_back(j, i);
			// double k = j;
			// ratio.push_back(k / i);
		}
	}
	sort(ratio.begin(), ratio.end(), [](ll a, ll b) {
		return (a.first*b.second < b.first*a.second);
	});

	for (int i = 1; i < ratio.size(); ++i)
	{
		if (ratio[i-1].first*ratio[i].second*p < ratio[i-1].second*ratio[i].first*100) {
			cout << "Time to change gears!";
			return 0;
		}
	}
	cout << "Ride on!";

	// double prev = ratio[0];
	// for (auto &i : ratio) {
	// 	if (((i - prev) / prev) > p) {
	// 		cout << "Time to change gears!";
	// 		return 0;
	// 	}
	// 	prev = i;
	// }
	// cout << "Ride on!";

	return 0;
}