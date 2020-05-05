#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using lls = pair<ll,string>;

int n,k,s,t,q;
string m;
unordered_set<string> us;

struct comp {
bool operator()(const lls &a, const lls &b) {
	if (a.first < b.first) return true; // swap when smaller
	return a.first == b.first && a.second > b.second; // swap when lexigographically larger
}
};
priority_queue<lls, vector<lls>, comp> pq;

ll calc(const ll &t, const ll &s) {
	return s - t * k;
}

void q2() {
	if (pq.empty()) {
		cout << "doctor takes a break\n";
		return;
	}

	// Lazy delete
	while (us.erase(pq.top().second) == 1)
		pq.pop();

	cout << pq.top().second << "\n";
	pq.pop();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("clinic.in", "r", stdin);

	cin>>n>>k;
	while (n--) {
		cin>>q;
		switch (q) {
			case 1:
				cin>>t>>m>>s;
				pq.emplace(calc(t,s), m);
				break;
			case 2:
				cin>>t; q2(); break;
			case 3:
				cin>>t>>m;
				us.insert(m);
				break;
		}
	}

	return 0;
}

/* SAME SPEED

bool isEmpty = true;
vector<lls> pq;

void q2() {
	if (pq.empty()) {
		cout << "doctor takes a break\n";
		isEmpty = true; return;
	}

	if (isEmpty) {
		make_heap(pq.begin(), pq.end(), comp());
		isEmpty = false;
	}

	// Lazy delete
	while (pq.size() && us.erase(pq.front().second) == 1) {
		pop_heap(pq.begin(), pq.end(), comp()); pq.pop_back();
		q2(); return; // recheck if isEmpty
	}

	cout << pq.front().second << "\n";
	pop_heap(pq.begin(), pq.end(), comp()); pq.pop_back();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("clinic.in", "r", stdin);

	cin>>n>>k;
	while (n--) {
		cin>>q;
		switch (q) {
			case 1:
				cin>>t>>m>>s;
				pq.emplace_back(calc(t,s), m);
				if (!isEmpty) { push_heap(pq.begin(), pq.end(), comp()); }
				break;
			case 2:
				cin>>t; q2(); break;
			case 3:
				cin>>t>>m;
				us.insert(m);
				break;
		}
	}

	return 0;
}
*/