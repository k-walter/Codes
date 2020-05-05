#include <bits/stdc++.h>
using namespace std;

/*
starting from direction of movement (ie shift left = start from left)
if adjacent equals, sum and skip next
at the end, shift all in direction
*/

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	freopen("2048.in", "r", stdin);

	vector<vector<int>> game(4, vector<int>(4));
	for (auto &row : game) {
		for (auto &ele : row) {
			cin >> ele;
		}
	}
	int move; cin >> move;

	switch (move) {
		case 0:// left
			for (auto &row: game) {
				// Shift empty
				for (int i = 1; i <= 3; ++i) {
					// non-zero
					if (row[i]) {
						int j = i - 1;
						while (j >= 0 && row[j] == 0)
							--j;
						++j;
						if (j != i)
							swap(row[j], row[i]);
					}
				}

				// Add adjacent numbers
				for (int i = 0; i < 3; ++i) {
					if (row[i] == 0) break;
					// non-zero and same as next
					if (row[i] == row[i+1]) {
						row[i] *= 2;
						row[++i] = 0;
					}
				}

				// Shift empty
				for (int i = 1; i <= 3; ++i) {
					// non-zero
					if (row[i]) {
						int j = i - 1;
						while (j >= 0 && row[j] == 0)
							--j;
						++j;
						if (j != i)
							swap(row[j], row[i]);
					}
				}
			}
			break;

		case 1: // up
			for (int i = 0; i <= 3; ++i) {
				// Shift empty
				for (int j = 1; j <= 3; ++j) {
					// non-zero
					if (game[j][i]) {
						int k = j - 1;
						while (k >= 0 && game[k][i] == 0)
							--k;
						++k;
						if (k != j)
							swap(game[k][i], game[j][i]);
					}
				}

				// Add adjacent numbers
				for (int j = 0; j < 3; ++j) {
					if (game[j][i] == 0) break;
					// non-zero and same as next
					if (game[j][i] == game[j+1][i]) {
						game[j][i] *= 2;
						game[++j][i] = 0;
					}
				}

				// Shift empty
				for (int j = 1; j <= 3; ++j) {
					// non-zero
					if (game[j][i]) {
						int k = j - 1;
						while (k >= 0 && game[k][i] == 0)
							--k;
						++k;
						if (k != j)
							swap(game[k][i], game[j][i]);
					}
				}
			}
			break;

		case 2: // right
			for (auto &row: game) {
				// Shift empty
				for (int i = 2; i >= 0; --i) {
					// non-zero
					if (row[i]) {
						int j = i + 1;
						while (j <= 3 && row[j] == 0)
							++j;
						--j;
						if (j != i)
							swap(row[j], row[i]);
					}
				}

				// Add adjacent numbers
				for (int i = 3; i > 0; --i) {
					if (row[i] == 0) break;
					// non-zero and same as next
					if (row[i] == row[i-1]) {
						row[i] *= 2;
						row[--i] = 0;
					}
				}

				// Shift empty
				for (int i = 2; i >= 0; --i) {
					// non-zero
					if (row[i]) {
						int j = i + 1;
						while (j <= 3 && row[j] == 0)
							++j;
						--j;
						if (j != i)
							swap(row[j], row[i]);
					}
				}
			}
			break;

		case 3: // down
			for (int i = 0; i <= 3; ++i) {
				// Shift empty
				for (int j = 2; j >= 0; --j) {
					// non-zero
					if (game[j][i]) {
						int k = j + 1;
						while (k <= 3 && game[k][i] == 0)
							++k;
						--k;
						if (k != j)
							swap(game[k][i], game[j][i]);
					}
				}

				// Add adjacent numbers
				for (int j = 3; j > 0; --j) {
					if (game[j][i] == 0) break;
					// non-zero and same as next
					if (game[j][i] == game[j-1][i]) {
						game[j][i] *= 2;
						game[--j][i] = 0;
					}
				}

				// Shift empty
				for (int j = 2; j >= 0; --j) {
					// non-zero
					if (game[j][i]) {
						int k = j + 1;
						while (k <= 3 && game[k][i] == 0)
							++k;
						--k;
						if (k != j)
							swap(game[k][i], game[j][i]);
					}
				}
			}
			break;
	}

	for (auto &row : game) {
		for (auto &ele: row) {
			cout << ele << " ";
		}
		cout << endl;
	}

	return 0;
}