#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  int sum = 0;
  string s;
  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    sum += (int)s[i] - 48;
  }

  cout << sum << endl;

  return 0;
}