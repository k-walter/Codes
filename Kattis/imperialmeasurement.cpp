#include <bits/stdc++.h>
using namespace std;

unordered_map<string,double> unit = {
	{ "thou", 1 },
	{ "th", 1 },
	{ "inch", 1000 },
	{ "in", 1000 },
	{ "foot", 12000 },
	{ "ft", 12000 },
	{ "yard", 36000 },
	{ "yd", 36000 },
	{ "chain", 792000 },
	{ "ch", 792000 },
	{ "furlong", 7920000 },
	{ "fur", 7920000 },
	{ "mile", 63360000 },
	{ "mi", 63360000 },
	{ "league", 190080000 },
	{ "lea", 190080000 },
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("imperialmeasurement.in", "r", stdin);

	string u,a,up; double n;
	cin>>n>>u>>a>>up;
	cout.precision(13);
	cout << n * unit[u] / unit[up];

	return 0;
}