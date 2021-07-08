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
    
struct vertex {
  char alphabet;
  bool exist;
  vll v;
  vector<vertex*> child;
  vertex(char a): alphabet(a), exist(false) { child.assign(26, NULL); v.assign(1,-1); }
};

class Trie {                                     // this is TRIE
private:                                         // NOT Suffix Trie
  vertex* root;
public:
  Trie() { root = new vertex('!'); }

  void insert(string word, ll idx) {                     // insert a word into trie
    vertex* cur = root;
    for (int i = 0; i < (int)word.size(); ++i) { // O(n)
		////cerr<<"still ok\n";
      (cur->v).pb(idx);
      int alphaNum = word[i]-'a';
      if (cur->child[alphaNum] == NULL)          // add new branch if NULL
        cur->child[alphaNum] = new vertex(word[i]);
      cur = cur->child[alphaNum];
    }
    (cur->v).pb(idx);
    cur->exist = true;
  }

  ll search(string word, ll idx) {                     // true if word in trie
    vertex* cur = root;
    ll ans=0;
    for (int i = 0; i < (int)word.size(); ++i) { // O(m)
	  ans+=lower_bound((cur->v).begin(),(cur->v).end(),idx)-(cur->v).begin();
	  if(*lower_bound((cur->v).begin(),(cur->v).end(),idx) != idx)ans--;
      int alphaNum = word[i]-'a';
      if (cur->child[alphaNum] == NULL)          // not found
        return ans;
      cur = cur->child[alphaNum];
    }
    ans+=lower_bound((cur->v).begin(),(cur->v).end(),idx)-(cur->v).begin();
    if(*lower_bound((cur->v).begin(),(cur->v).end(),idx) != idx)ans--;
    return ans;                           // check exist flag
  }

  bool startsWith(string prefix) {               // true if match prefix
    vertex* cur = root;
    for (int i = 0; i < (int)prefix.size(); ++i) {
      int alphaNum = prefix[i]-'a';
      if (cur->child[alphaNum] == NULL)          // not found
        return false;
      cur = cur->child[alphaNum];
    }
    return true;                                 // reach here, return true
  }
};

unordered_map<string, int> a;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Trie trie;
	int n;cin>>n;
	//cin.get();
	F0R(i,n){
		string s;cin>>s;
		a[s]=i;
		trie.insert(s,i);
	}
	int q;cin>>q;//cin.get();
	while(q--){
		string s;cin>>s;
		int idx=((a.find(s)!=a.end())?a[s]:(n-1));
		cout<<trie.search(s,idx)<<'\n';
	}

}
