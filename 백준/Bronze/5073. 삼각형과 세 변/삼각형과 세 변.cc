#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  while (1) {
    int a, b, c, tmp;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) { //마지막 줄인 경우
      break;
    } else if (a == b && b == c) { //정삼각형인 경우
      cout << "Equilateral"
           << "\n";
      continue;
    } else if ((a >= b + c) || (b >= c + a) ||
               (c >= a + b)) { //하나라도 true가 나오면, invalid
      cout << "Invalid"
           << "\n";
      continue;
    } else if (a == b || b == c || c == a) { //하나라도 true가 나오면, Isosceles
      cout << "Isosceles"
           << "\n";
      continue;
    } else {
      cout << "Scalene"
           << "\n";
      continue;
    }
  }

  return 0;
}
