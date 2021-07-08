#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
#define INF 1e9
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORi(i, a, b) for (int i = (a); i <= (b); ++i)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define LSOne(S) ((S) & -(S))
#define fst first
#define snd second
#define all(c) c.begin(), c.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef tuple<int,int,ll> iii;
typedef pair<ll,ll> pll;
typedef vector<ii> vii;
typedef vector<pll> vpll;
typedef tuple<int,ll,ll> edge;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vdit;
typedef gp_hash_table<int, pair<tuple<int,int,int>,tuple<int,int,int>>, hash<int>, equal_to<int>, direct_mod_range_hashing<int>, linear_probe_fn<>,
                      hash_standard_resize_policy<hash_prime_size_policy, hash_load_check_resize_trigger<true>, true>>
    gp;

void solve() {
    int V,E; cin>>V>>E;
    multiset<iii> el;
    vi deg(V+1, 0);
    F0R(i,E) {
        int u,v; ll w; cin>>u>>v>>w;
        el.emplace(u,v,w);
        el.emplace(v,u,w);
        ++deg[u]; ++deg[v]; }
    F0R(u,V+1) {
        if (deg[u] != 2) continue;
        
        auto it = el.lower_bound({u,0,0});
        auto [_,v1,w1] = *it;
        el.erase(el.find({v1, u, w1}));
        
        auto it2 = it; ++it2;
        auto [__,v2,w2] = *it2;
        el.erase(el.find({v2, u, w2}));
        
        el.erase(it2); el.erase(it);
        el.emplace(v1, v2, w1+w2);
        el.emplace(v2, v1, w1+w2);
    }
    
    cout << (el.size()/2) << "\n";
    int pu=0, pv=0;
    for (auto &[u,v,w] : el) {
        if (u > v) continue;
        if (u==v and pu==u and pv==v) { pu=0; continue; }
        cout << u << " " << v << " " << w << "\n";
        pu=u; pv=v;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin>>t;
    while (t--) solve();
    
}