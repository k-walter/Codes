#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxStudents(const vector<vector<char>>& seats) {
        vector<int> col(seats[0].size(), 0);
        for (auto &row : seats) {
            for (int i=0; i<row.size(); ++i)
                if (row[i]=='.') ++col[i];
        }
        int ans = 0;
        for (int i=0; i<col.size(); ++i) {
            if (i+1 == col.size()) { ans+=col[i]; break; }
            if (col[i]<col[i+1] && (i+2==col.size() || col[i+1]<=col[i+2])) continue;
            ans += col[i]; ++i;
            cout << i << " " << ans << "\n";
        }
        return ans;
    }
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen(".in", "r", stdin);

	vector<vector<char>> v = {{'#','.','#','#','.','#'},
                {'.','#','#','#','#','.'},
                {'#','.','#','#','.','#'}};
	Solution s; cout << s.maxStudents(v);

	return 0;
}