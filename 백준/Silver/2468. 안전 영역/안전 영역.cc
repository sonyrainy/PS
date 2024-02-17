// days 2차원 배열을 써서 가장 최대값을 넣으려고 했음.
//근데 bfs 쓰면 그냥 바로 최소값이 나온다는 것을 알음.
//걍 count로 하면 될 것 같다는 생각.

//+ 검색) 그냥 box에다가 바로 날짜를 넣어가면
//되네

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 101;
int h[MAX_N][MAX_N];

vector<int> F;

int bfs(int i, int n) {
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, 1, 0, -1};
  int cnt = 0;
  int check[MAX_N][MAX_N] = {
      0,
  };
  queue<pair<int, int>> q;

  for (int a = 1; a <= n; a++) {
    for (int b = 1; b <= n; b++) {
      // i보다 큰 곳에 있고, 방문한 적이 없는 곳일 때
      // 영역의 시작 부분
      if (h[a][b] > i && check[a][b] == 0) {
        check[a][b] = ++cnt;
        q.push({a, b});

        while (!q.empty()) {
          int x = q.front().first;
          int y = q.front().second;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int xx = x + dx[k];
            int yy = y + dy[k];

            if (xx < 1 || xx > n || yy < 1 || yy > n) {
              continue;
            }
            if (h[xx][yy] > i && check[xx][yy] == 0) {
              q.push({xx, yy});
              check[xx][yy] = cnt;
              //중복 메모리 초과 주의
              // queue에 넣으며 동시에 방문 여부를 체크하는게 국룰
            }
          }
        }
      }
    }
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> h[i][j];
    }
  }

  for (int i = 1; i <= 100; i++) {
    F.push_back(bfs(i, n));
  }

  if (*max_element(F.begin(), F.end()) == 0) {
    cout << 1;
  } else {
    cout << *max_element(F.begin(), F.end());
  }

  return 0;
}
