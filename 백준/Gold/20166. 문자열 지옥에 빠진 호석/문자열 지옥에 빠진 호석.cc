#include <bits/stdc++.h>
using namespace std;

string board[10];
int n, m, k;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
unordered_map<string, int> cnt;

void dfs(int x, int y, string s) {
    cnt[s]++;
    if (s.size() == 5) return;

    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        // 좌표 래핑 처리
        if (nx < 0) nx = n - 1;
        if (nx >= n) nx = 0;
        if (ny < 0) ny = m - 1;
        if (ny >= m) ny = 0;

        dfs(nx, ny, s + board[nx][ny]);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> board[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dfs(i, j, string(1, board[i][j]));
        }
    }

    while (k--) {
        string s;
        cin >> s;
        cout << cnt[s] << '\n';
    }
}
