#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<string> g(N);
	for (int i = 0; i < N; ++i) cin >> g[i];

	const int dx[8] = { -1,-1,-1, 0,0, 1,1,1 };
	const int dy[8] = { -1, 0, 1,-1,1,-1,0,1 };

	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			for (int d = 0; d < 8; ++d) {
				int x1 = i + dx[d], y1 = j + dy[d];
				int x2 = i + 2 * dx[d], y2 = j + 2 * dy[d];
				if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= M) continue;

				char c0 = g[i][j];
				char c1 = g[x1][y1];
				char c2 = g[x2][y2];

				if ((c0 == 'F' && c1 == 'O' && c2 == 'X')) {
					++ans;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
