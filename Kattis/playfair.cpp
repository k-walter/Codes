#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("playfair.in", "r", stdin);

	string line; getline(cin,line);
	int ati[26], ita[25], it = 0, nxt;
	memset(ati, -1, sizeof ati); ati['q'-'a'] = 0;
	for (auto &c:line)
		if (isalpha(c) && ati[c-'a']==-1) {
			ita[it] = c-'a';
			ati[c-'a'] = it++;
		}
	for (int i = 0; i < 26; ++i)
		if (ati[i]==-1) {
			ita[it] = i;
			ati[i] = it++;
		}
	getline(cin,line);
	line.erase(remove(line.begin(),line.end(),' '), line.end());
	for (int i = 0; i < line.length(); ++i) {
		it = ati[line[i]-'a'];
		nxt = ati[((i+1 == line.length() || line[i]==line[i+1]) ? 'x' : line[++i]) - 'a'];
		if (it/5 == nxt/5) { // same row
			cout << (char)(ita[(it+1)%5 ? it+1 : it-4]+'A');
			cout << (char)(ita[(nxt+1)%5 ? nxt+1 : nxt-4]+'A');
		} else if (it%5 == nxt%5) { // same col
			cout << (char)(ita[(it+5)%25]+'A');
			cout << (char)(ita[(nxt+5)%25]+'A');
		} else {
			cout << (char)(ita[(it/5)*5 + nxt%5]+'A');
			cout << (char)(ita[(nxt/5)*5 + it%5]+'A');
		}
	}

	return 0;
}