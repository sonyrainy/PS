#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int arr[1001][1001] = {
    0,
};
int arrinf[1001][1001][2] = {
    0,
};
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int n, m;

int BFS() {
  //(1, 1), (N, M)은 항상 0.
  // x, y로의 위치, 부쉈는지 여부, cnt
  queue<pair<pair<int, int>, pair<int, int>>> q;

  q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));

  arrinf[0][0][0] = 1;
  while (!q.empty()) {
    int x = q.front().first.first;
    int y = q.front().first.second;

    int crush = q.front().second.first;
    int cnt = q.front().second.second;
    q.pop();

    if (x == n - 1 && y == m - 1) {
      return cnt;
    }

    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];

      // 범위 벗어나면 무시
      if (xx < 0 || yy < 0 || xx >= n || yy >= m) {
        continue;
      }
      // 부수지 않은 상태로 0 인 곳을 갈 때
      if (crush == 0 && arr[xx][yy] == 0 && arrinf[xx][yy][0] == 0) {
        q.push(make_pair(make_pair(xx, yy), make_pair(crush, cnt + 1)));
        arrinf[xx][yy][0] = cnt + 1;

      }
      // 부수지 않은 상태로 1 인 곳을 갈 때
      else if (crush == 0 && arr[xx][yy] == 1 && arrinf[xx][yy][1] == 0) {
        q.push(make_pair(make_pair(xx, yy), make_pair(crush + 1, cnt + 1)));
        arrinf[xx][yy][1] = cnt + 1;

      }
      // 부순 상태로 0 인 곳을 갈 때
      else if (crush == 1 && arr[xx][yy] == 0 && arrinf[xx][yy][1] == 0) {
        q.push(make_pair(make_pair(xx, yy), make_pair(crush, cnt + 1)));
        arrinf[xx][yy][1] = cnt + 1;

      }
      // 부순 상태로 1 인 곳을 갈 때
      else {
        continue;
      }
    }
  }
  return -1;
}

int main() {
  ios_base ::sync_with_stdio(false);
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

  cout << BFS();

  return 0;
}
