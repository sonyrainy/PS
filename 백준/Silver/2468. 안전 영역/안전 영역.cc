#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_N = 101;
int h[MAX_N][MAX_N];
int check[MAX_N][MAX_N] = {
    0,
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> F;
int n;

// i보다 지대가 높아야 안전지대, n은 지역 가로세로
void dfs(int i, int a, int b) {
  check[a][b] = 1;
  for (int k = 0; k < 4; k++) {
    int xx = a + dx[k];
    int yy = b + dy[k];
    if (xx < 1 || xx > n || yy < 1 || yy > n) {
      continue;
    }
    if (h[xx][yy] > i && check[xx][yy] == 0) {
      dfs(i, xx, yy);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> h[i][j];
    }
  }

  for (int i = 1; i <= 100; i++) {
    fill(&check[0][0], &check[0][0] + MAX_N * MAX_N, 0);
    int cnt = 0;
    for (int a = 1; a <= n; a++) {
      for (int b = 1; b <= n; b++) {
        if (h[a][b] > i && check[a][b] == 0) {
          dfs(i, a, b);
          cnt++;
          // dfs를 쓰고, cnt를 누적.
        }
      }
    }
    F.push_back(cnt);
    // max_safe_zone = max(max_safe_zone, cnt);
  }

  if (*max_element(F.begin(), F.end()) == 0) {
    cout << 1;
  } else {
    cout << *max_element(F.begin(), F.end());
  }
  return 0;
}
