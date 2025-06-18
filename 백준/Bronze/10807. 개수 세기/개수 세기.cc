#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  int *a = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int v;
  cin >> v;
  int count = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] == v) {
      count++;
    }
  }
  cout << count;
  return 0;
}