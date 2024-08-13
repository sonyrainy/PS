#include <cmath>
#include <iostream>

using namespace std;

int is_sosu[1000001]; // 0이면 소수, 1이면 소수 아님

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 초기화: 0과 1은 소수가 아님
  is_sosu[0] = is_sosu[1] = 1;

  // 에라토스테네스의 체
  for (int i = 2; i <= sqrt(1000000); i++) {
    if (is_sosu[i] == 0) { // i가 소수라면
      for (int j = i * i; j <= 1000000; j += i) {
        is_sosu[j] = 1; // i의 배수들은 소수가 아님
      }
    }
  }

  int n;
  while (true) {
    cin >> n;
    if (n == 0) {
      break;
    }
    bool found = false;

    for (int i = 3; i <= n / 2; i += 2) {
      if (is_sosu[n - i] == 0 && is_sosu[i] == 0) { // 두 수가 모두 소수라면
        cout << n << " = " << i << " + " << n - i << "\n";
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "Goldbach's conjecture is wrong."
           << "\n";
    }
  }
  return 0;
}
