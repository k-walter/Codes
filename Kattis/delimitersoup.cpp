#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("delimitersoup.in", "r", stdin);

    string line; 
    getline(cin, line);getline(cin, line);
    stack<char> s;
    for (int i = 0; i < line.size(); ++i) {
        const char &c = line[i];
        switch (c) {
        case '(':case '[':case '{':
            s.push(c);
            break;
        case ')':
            if (s.empty() || s.top() != '(') {
                cout << c << " " << i;
                return 0;
            }
            s.pop();
            break;
        case ']':
            if (s.empty() || s.top() != '[') {
                cout << c << " " << i;
                return 0;
            }
            s.pop();
            break;
        case '}':
            if (s.empty() || s.top() != '{') {
                cout << c << " " << i;
                return 0;
            }
            s.pop();
            break;
        }
    }
    cout << "ok so far";

    return 0;
}