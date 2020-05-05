#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;

constexpr int MAXN = 5555;
using bs = bitset<MAXN>;
int n, m, q;
bs graph[2][MAXN];

void dump(int trans, int neg) {
    return;
    cout << "n = " << n << '\n';
    for (int u = 0; u < n; ++u) {
        for (int v = 0; v < n; ++v) {
            cout << ((u == v) ? 0 : (graph[trans][u][v] ^ neg));
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("abinitio.in", "r", stdin);

    cin >> n >> m >> q;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        graph[0][u].set(v);
        graph[1][v].set(u);
    }

    int trans = 0;
    int neg = 0;
    // dump(trans, neg);
    while (q-- > 0) {
        int op;
        int u, v;
        cin >> op;
        if (op == 1) {
            for (int i = 0; i < n; ++i) {
                graph[0][i].set(n, neg);
                graph[1][i].set(n, neg);
                graph[0][n].set(i, neg);
                graph[1][n].set(i, neg);
            }
            ++n;
        } else if (op == 2 or op == 4) {
            cin >> u >> v;
            assert(u != v);
            graph[trans][u].flip(v);
            graph[trans ^ 1][v].flip(u);
        } else if (op == 3) {
            cin >> u;
            for (v = 0; v < n; ++v) {
                if (u == v) continue;

                graph[0][u].set(v, neg);
                graph[0][v].set(u, neg);
                graph[1][u].set(v, neg);
                graph[1][v].set(u, neg);
            }
        } else if (op == 5) {
            trans ^= 1;
        } else if (op == 6) {
            neg ^= 1;
        }
        // dump(trans, neg);

        for (int u = 0; u < n; ++u) {
            cout << u << " | ";
            for (int v = 0; v < n; ++v) {
                cout << graph[trans][u][v];
            }
            cout << "\n";
        }
        cout << "\n";
    }

    constexpr int MOD = 1e9 + 7;
    cout << n << '\n';
    for (int u = 0; u < n; ++u) {
        vector<int> adj;
        for (int v = n - 1; v >= 0; --v) {
            if (u == v) continue;

            if (graph[trans][u][v] ^ neg) {
                adj.push_back(v);
            }
        }

        ll res = 0;
        for (int v : adj) {
            res = (7LL * res + v) % MOD;
        }
        cout << adj.size() << ' ' << res << '\n';
    }

    return 0;
}