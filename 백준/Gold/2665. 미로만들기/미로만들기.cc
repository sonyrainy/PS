#include <cmath>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>

using namespace std;

int ROOM[51][51] = {
    0,
};
int visit[51][51];
int minValue = 2147000000;
// int temp = 0;

void BFS(int n) {
  queue<pair<int, int>> q;

  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  q.push(make_pair(1, 1));
  visit[1][1] = 0;

  while (!q.empty()) {

    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    // BFS 돌리면서 변경되는 횟수 찾기
    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx < 1 || xx > n || yy < 1 || yy > n) {
        continue;
      }

      // 다음에 갈 곳이 검은 곳이면,
      else if (ROOM[xx][yy] == 0) {
        int temp = visit[x][y] + 1;
        // 다음에 간 곳을 갈 때까지의 변동되는 최솟값을
        // visit에 넣는다.
        // 즉, 최근에 연산한 값이 visit의 값보다 작으면
        // visit 값을 최신화한다.
        if (temp < visit[xx][yy]) {
          visit[xx][yy] = temp;
          q.push(make_pair(xx, yy));
        }
      }

      // 다음에 갈 곳이 흰 색이면서, 이전에 있던
      // 값보다 크면
      // 그대로 visit을 유지한 채 옮김.
      else if (ROOM[xx][yy] == 1) {
        int temp = visit[x][y];

        if (temp < visit[xx][yy]) {
          visit[xx][yy] = visit[x][y];
          q.push(make_pair(xx, yy));
        }
      }
    }
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    string line;
    cin >> line;
    for (int j = 1; j <= n; j++) {
      ROOM[i][j] = line[j - 1] - '0';
      visit[i][j] = 2147000000;
    }
  }
  BFS(n);
  cout << visit[n][n] << "\n";

  return 0;
}
