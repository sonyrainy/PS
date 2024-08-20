#include <iostream>
#include <queue>
#include <string>
using namespace std;

int arr[1001][1001]; // 지도 배열
int arrinf[1001][1001][2]; // 방문 배열: [x][y][벽을 부쉈는지 여부]
int dx[4] = {-1, 0, 1, 0}; // 상하좌우 이동
int dy[4] = {0, -1, 0, 1};
int n, m;

int BFS() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));

    arrinf[0][0][0] = 1; // 시작점 방문 기록

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int crush = q.front().second.first; // 벽을 부쉈는지 여부
        int cnt = q.front().second.second; // 현재 이동 횟수
        q.pop();

        // 도착 지점에 도달하면 이동 횟수 반환
        if (x == n - 1 && y == m - 1) {
            return cnt;
        }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            // 범위를 벗어나면 무시
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;

            // 벽을 부수지 않고 이동하는 경우
            if (arr[xx][yy] == 0 && arrinf[xx][yy][crush] == 0) {
                arrinf[xx][yy][crush] = cnt + 1;
                q.push(make_pair(make_pair(xx, yy), make_pair(crush, cnt + 1)));
            }

            // 벽을 부수고 이동하는 경우 (한 번만 가능)
            if (arr[xx][yy] == 1 && crush == 0 && arrinf[xx][yy][1] == 0) {
                arrinf[xx][yy][1] = cnt + 1;
                q.push(make_pair(make_pair(xx, yy), make_pair(1, cnt + 1)));
            }
        }
    }

    return -1; // 도달할 수 없는 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            arr[i][j] = line[j] - '0';
        }
    }

    int result = BFS();

    if (result != -1) {
        cout << result << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
