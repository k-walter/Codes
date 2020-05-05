#include <bits/stdc++.h>
using namespace std;

string alpha = "abcdefghijklmnoprstuvwxyz";
const int diff = 'A' - 'a';

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("playfair.in", "r", stdin);

    unordered_map<char,pair<int,int>> m(26*2);
    vector<vector<char>> vv(5, vector<char>(5));
    int i = 0;

    // Cipher
    string line; getline(cin, line);
    for (char &c : line)
        if (m.find(c) == m.end() && isalpha(c)) {
            m.emplace(c, make_pair(i/5, i%5));
            vv[i++/5][i%5] = c;
        }

    for (char &c : alpha)
        if (m.find(c) == m.end()) {
            m.emplace(c, make_pair(i/5, i%5));
            vv[i++/5][i%5] = c;
        }

    // Encryption
    getline(cin, line);
    queue<char> q;
    for (char &c : line)
        if (isalpha(c))
            q.emplace(c);
    
    while (q.size()) {
        char a = q.front(); q.pop();
        char b;
        if (q.empty() || a == q.front()) b = 'x';
        else {
            b = q.front(); q.pop();
        }

        if (m[a].first == m[b].first) { // same row
            cout << (char)(vv[m[a].first][(m[a].second+1) % 5] + diff);
            cout << (char)(vv[m[b].first][(m[b].second+1) % 5] + diff);
        }
        else if (m[a].second == m[b].second) { // same col
            cout << (char)(vv[(m[a].first+1) % 5][m[a].second] + diff);
            cout << (char)(vv[(m[b].first+1) % 5][m[b].second] + diff);
        } else {
            cout << (char)(vv[m[a].first][m[b].second] + diff);
            cout << (char)(vv[m[b].first][m[a].second] + diff);
        }
    }

    // for (int i = 0; i < line.size(); ++i) {
    //  while (i < line.size() && !isalpha(line[i])) ++i;
    //  char a = line[i++];

    //  while (!isalpha(line[i])) ++i;
    //  char b = ((i == line.size()-1 || a == line[i]) ? 'x' : line[++i]);

    //  if (m[a].first == m[b].first) { // same row
    //      cout << (char)(vv[m[a].first][(m[a].second+1) % 5] + diff);
    //      cout << (char)(vv[m[b].first][(m[b].second+1) % 5] + diff);
    //  }
    //  else if (m[a].second == m[b].second) { // same col
    //      cout << (char)(vv[(m[a].first+1) % 5][m[a].second] + diff);
    //      cout << (char)(vv[(m[b].first+1) % 5][m[b].second] + diff);
    //  } else {
    //      cout << (char)(vv[m[a].first][m[b].second] + diff);
    //      cout << (char)(vv[m[b].first][m[a].second] + diff);
    //  }
    // }

    return 0;
}