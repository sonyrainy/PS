#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int n, m;

//방문 여부
int visited[101][101];
//실제 값 받을 곳
char map[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int x, int y) {
  int xx, yy;
  visited[x][y] = 1;

  queue<pair<int, int>> q;
  q.push(make_pair(x, y));

  // 큐가 비어있을 때까지 반복
  while (q.empty() == false) {
    x = q.front().first;
    y = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      xx = x + dx[i];
      yy = y + dy[i];

      if (xx >= 0 && xx < n && yy >= 0 && yy < m) {

        // 방문된 적 없고, 지나갈 수 있는 곳이라면
        if (visited[xx][yy] == 0 && map[xx][yy] == '1') {
          visited[xx][yy] = visited[x][y] + 1;
          q.push(make_pair(xx, yy));
        }
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  visited[0][0] = 1;

  BFS(0, 0);

  cout << visited[n - 1][m - 1];

  return 0;
}
