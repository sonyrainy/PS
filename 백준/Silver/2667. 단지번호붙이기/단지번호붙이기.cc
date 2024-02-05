#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
char map[26][26];
int check[26][26]; //정점 방문 여부
vector<int> cnts;

int cnt = 0;
int n = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void dfs(int x, int y) {
  int xx, yy;

  //발견하면 수색시작하자.
  if (map[x][y] == '1' && check[x][y] == 0) {
    cnt++;
    check[x][y] = 1;

    for (int i = 0; i < 4; i++) { //찾은 곳에서 둘러보기
      xx = x + dx[i];
      yy = y + dy[i];
      if (xx < 0 || xx >= n || yy < 0 || yy >= n)
        continue;
      if (map[xx][yy] == '1' && check[xx][yy] == 0) { //붙어있고, 방문X
        dfs(xx, yy);
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> map[i];
  }
  for (int j = 0; j < n; j++) {
    int c = 0;
    for (int i = 0; i < n; i++) {
      dfs(i, j);
      if (cnt != 0) {
        cnts.push_back(cnt);
      }
      cnt = 0;
    }
  }
  sort(cnts.begin(), cnts.end());

  cout << cnts.size() << "\n";

  for (int i = 0; i < cnts.size(); i++) {
    cout << cnts[i] << "\n";
  }
  return 0;
}
