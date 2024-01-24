#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  cin >> N;
  vector<int> v(N + 1);
  v[1] = 0;
  v[2] = 1;
  v[3] = 1;

  for (int i = 4; i <= N; i++) {
    if (i % 3 == 0 && i % 2 == 0) {
      v[i] = min({v[i - 1], v[i / 3], v[i / 2]}) + 1;
    } else if (i % 3 == 0) {
      v[i] = min(v[i - 1], v[i / 3]) + 1;
    } else if (i % 2 == 0) {
      v[i] = min(v[i - 1], v[i / 2]) + 1;
    } else {
      v[i] = v[i - 1] + 1;
    }
  }

  cout << v[N];

  return 0;
}