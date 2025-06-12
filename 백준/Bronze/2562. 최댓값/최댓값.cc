#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a[9];
  // int *a = new int[N];
  for (int i = 0; i < 9; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < 9; i++) {
    if (a[i] == *max_element(a, a + 9)) {
      cout << a[i] << endl;
      cout << i+1 << endl;
    }
  }
  return 0;
}