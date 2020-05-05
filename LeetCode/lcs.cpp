#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
class Solution {
public:
    // vector<vi> mem;
    int longestCommonSubsequence(string t1, string t2, int i = 0, int j = 0) {
        if (t1.size() < t2.size()) swap(t1, t2);
        int n = t1.size(), m = t2.size();
        vector<vi> mem(2, vi(m+1)); bool cur = 0;
        mem[0][0] = mem[1][0] = 0;
        printf("\t"); for (auto &i : t2) printf("%c\t", i); printf("\n");
        for (int i = 1; i <= n; ++i) {
            cur = !cur;
            for (int j = 1; j <= m; ++j) {
                if (t1[i-1] == t2[j-1]) mem[cur][j] = 1 + mem[!cur][j-1];
                else mem[cur][j] = max(mem[!cur][j], mem[cur][j-1]);
                // if (t1[i]==t2[j]) mem[cur][j] = 1 + ((i && j) ? mem[!cur][j-1] : 0);
                // if (i) mem[cur][j] = max(mem[cur][j], mem[!cur][j]);
                // if (j) mem[cur][j] = max(mem[cur][j], mem[cur][j-1]);
            }
            printf("%c\t", t1[i-1]);
            for (int j = 1; j <= m; ++j) {
                printf("%d\t", mem[cur][j]);
            }
            printf("\n");
        }
        return mem[cur][m];
        // if (i >= t1.size() || j >= t2.size()) return 0;
        // if (t1[i] == t2[j]) return 1 + longestCommonSubsequence(t1,t2,i+1,j+1);
        // if (mem.empty()) mem.assign(t1.size(), vi(t2.size(), -1));
        // auto &ans = mem[i][j];
        // if (ans != -1) return ans;
        // return ans = max(longestCommonSubsequence(t1,t2,i,j+1), longestCommonSubsequence(t1,t2,i+1,j));
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // freopen(".in", "r", stdin);

    Solution s;
    printf("%d\n", s.longestCommonSubsequence("abcde", "ace"));
    // i\j     0   1   2   3   4   5
    // 0
    // 1
    // 2
    // 3
    // 4
    // 5                           

    return 0;
}