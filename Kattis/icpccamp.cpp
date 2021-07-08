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

vi a,b;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,p,q;ll s;cin>>n>>p>>q>>s;
	F0R(i,p){
		ll x;cin>>x;
		a.pb(x);
	}
	F0R(i,q){
		ll x;cin>>x;
		b.pb(x);
	}
	sort(a.begin(),a.end());
	sort(b.rbegin(),b.rend());
	int ans=INF+1;
	ll lo=0,hi=1e9;
	while(lo<=hi){
		ll mid=(lo+hi)>>1;
		int idx=0;
		multiset<ll> cand;
		int cnt=0;
		F0R(i,q){
			while(idx<p && b[i]+a[idx]<=s){
				cand.insert(-a[idx]);
				idx++;
			}
			if(cand.lower_bound(-(b[i]+mid))!=cand.end() && -*(cand.lower_bound(-(b[i]+mid)))>=b[i]-mid){
				cnt++;
				cand.erase(cand.lower_bound(-(b[i]+mid)));
			}
		}
		if(cnt>=n){
			ans=mid;
			hi=mid-1;
		}else{
			lo=mid+1;
		}
	}
	if(ans==INF+1){
		cout<<-1<<'\n';
		return 0;
	}
	cout<<ans<<'\n';
}
