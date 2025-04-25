#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>

using namespace std;

#define X first
#define Y second

int arr[501][501];
int visit[501][501];
int cnt=0;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int maxN = 0;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    queue<pair<int, int>> Q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        // 길이 있고, 방문하지 않은 곳
            if (arr[i][j] == 1 && visit[i][j] == 0) {
                cnt++;
                int t = 1;
                visit[i][j] = 1;
                Q.push({ i, j });
                while (!Q.empty()) {
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = cur.X + dx[k];
                        int ny = cur.Y + dy[k];
                        if (nx < 0 || nx >= n|| ny < 0 || ny >= m) continue;
                        if (visit[nx][ny] == 1 || arr[nx][ny] == 0) continue;
                        t++;
                        visit[nx][ny] = 1;
                        Q.push({ nx, ny });
                    
                    }
                }
                if (t > maxN) maxN = t;


            }
        }
    }

    cout << cnt << "\n" << maxN;

    return 0;
}
