// days 2차원 배열을 써서 가장 최대값을 넣으려고 했음.
//근데 bfs 쓰면 그냥 바로 최소값이 나온다는 것을 알음.
//걍 count로 하면 될 것 같다는 생각.

//+ 검색) 그냥 box에다가 바로 날짜를 넣어가면
//되네

#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 1001;

int box[MAX_N][MAX_N];
int cnt = 0;

int bfs(int m, int n) {
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};

  queue<pair<int, int>> q;

  // 모든 익은 토마토를 큐에 넣고 익는 날짜를 초기화
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (box[i][j] == 1) {
        q.push({i, j});
      }
    }
  }

  //일단 큐에 들어왔다는거 자체가 익은(익을) 토마토인 것임.
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    int nextbox = 0;
    q.pop();

    for (int k = 0; k < 4; k++) {
      int xx = x + dx[k];
      int yy = y + dy[k];

      if (xx < 1 || xx > n || yy < 1 || yy > m)
        continue;

      if (box[xx][yy] == 0) {
        q.push({xx, yy});
        box[xx][yy] = box[x][y] + 1;
        cnt = box[xx][yy];
        // 익는 날짜 기록
        // BFS로는 어차피 다돌면 최소 날짜가 계산됨.
        //따라서 전체 배열에서 최대 값을 구하면
        //어차피 다 익는 최소 날짜임을 알 수 있음.
      }
    }
  }
  // 아직 익지 않은 토마토가 있는지 확인
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (box[i][j] == 0)
        return -1; // 모든 토마토가 익지 않은 상태
    }
  }
  if (cnt == 0) {
    return 0;
  } else {
    return cnt - 1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int m, n;
  cin >> m >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> box[i][j];
    }
  }

  int result = bfs(m, n);
  cout << result;

  return 0;
}
