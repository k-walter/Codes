ch#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

class PQ {
private:
	int heap_size;
	vector<ii> pq; // idx to infection
	unordered_map<string, int> m; // name to idx
	unordered_map<int, string> m_idx; // idx to name

	int parent(int& i) { return i >> 1; }
	int left(int& i) { return i << 1; }
	int right(int& i) { return (i << 1) + 1; }
	bool larger(int a, int b) {
		if (pq[a].first > pq[b].first) return true;
		return (pq[a].first == pq[b].first && pq[a].second > pq[b].second);
	}

	void swapz(int a, int b) {
		if (a == b) return;
		// swap idx to name
		string tmp = m_idx[a];
		m_idx[a] = m_idx[b];
		m_idx[b] = tmp;

		// Swap name to idx
		m[m_idx[a]] = a;
		m[m_idx[b]] = b;

		// Swap infection levels
		swap(pq[a], pq[b]);
	}

	void bubble_up(int i) {
		while (i > 1 && larger(i, parent(i))) {
			swapz(i, parent(i));
			i >>= 1;
		}
	}
	void bubble_down(int i) {
		while (left(i) <= heap_size) {
			int i2 = i;
			if (larger(left(i),i))
				i2 = left(i);
			if (right(i) <= heap_size && larger(right(i), i2))
				i2 = right(i);
			if (i == i2) return;
			swapz(i, i2);
			i = i2;
		}
	}

public:
	PQ() {
		pq.clear();
		pq.emplace_back(0, 0); // 1-based
		heap_size = 0;
	}

	void push(string& name, int& lvl, int& n) {
		pq.emplace_back(lvl, n);
		// m[name] = ++heap_size;
		// m_idx[m[name]] = name;
		m.emplace(name, ++heap_size);
		m_idx.emplace(m[name], name);
		bubble_up(heap_size);
	}

	void update(string& name, int& amt) {
		int idx = m[name];
		pq[idx].first += amt;
		bubble_up(idx);
	}

	void remove(string& name) {
		int idx = m[name]; // new index
		if (idx != heap_size) {
			swapz(idx, heap_size);
			larger(heap_size--, idx) ? bubble_down(idx) : bubble_up(idx); // old > new
		} else { --heap_size; }

		pq.pop_back(); // remove infection
		m.erase(name); // remove name
		m_idx.erase(heap_size + 1); // remove index
	}

	void top() {
		cout << (heap_size > 0 ? m_idx[1] : "The clinic is empty") << "\n";
	}

	void print() {
		for (int i = 1; i <= heap_size; ++i)
			cout << m_idx[i] << " " << pq[i].first << " " << pq[i].second << ", ";
		cout << "\n";// << "MAP: ";
		// for (auto &i : m)
		// 	cout << i.first << " " << i.second << ", ";
		// cout << "\n";
	}
	
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// freopen("doctorkattis.in", "r", stdin);

	PQ pq;
	int n; cin >> n;
	string name; int lvl;
	while (n--) {
		int q; cin >> q;
		switch (q) {
			case 0:
				cin >> name >> lvl;
				// cout << q << " " << name << " " << lvl << "\n";
				pq.push(name, lvl, n);
				break;
			case 1:
				cin >> name >> lvl;
				// cout << q << " " << name << " " << lvl << "\n";
				pq.update(name, lvl);
				break;
			case 2:
				cin >> name;
				// cout << q << " " << name << "\n";
				pq.remove(name);
				break;
			case 3:
				// cout << q << "\n";
				pq.top();
				break;
		};
		// pq.print(); cout << "\n";
	}

	return 0;
}