#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;

vector<int> visit(100001, 0);
int n;
int k;

void BFS(int v) {
  q.push(v);

  while (!q.empty()) {
    v = q.front();
    q.pop();

    if (v == k) {
      cout << visit[k] << "\n";
      break;
    }
    if (v - 1 >= 0 && visit[v - 1] == 0) {
      visit[v - 1] = visit[v] + 1;
      q.push(v - 1);
    }
    if (v + 1 <= 100000 && visit[v + 1] == 0) {
      visit[v + 1] = visit[v] + 1;
      q.push(v + 1);
    }
    if (v * 2 < 100001 && visit[v * 2] == 0) {
      visit[v * 2] = visit[v] + 1;
      q.push(v * 2);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  BFS(n);

  return 0;
}