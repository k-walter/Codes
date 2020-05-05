#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mem;
    int dp(string &s, int i = 0) {
        if (i >= s.size()) return 1;
        if (s[i] == '0') return 0;
        int &ans = mem[i];
        if (ans != -1) return ans;
        // 1 digit
        ans = dp(s, i+1);
        // 2 digit
        if (i+2<=s.size() && (s[i]=='1' || s[i]=='2' && s[i+1]<='6'))
            ans += dp(s, i+2);
        return ans;
    }
    int numDecodings(string &s) {
        mem.assign(s.size()+1, -1);
        return dp(s);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("decodeways.in", "r", stdin);

    string line;
    Solution s;
    while (getline(cin,line), !cin.eof()) {
        cout << s.numDecodings(line) << "\n";
    }

    return 0;
}