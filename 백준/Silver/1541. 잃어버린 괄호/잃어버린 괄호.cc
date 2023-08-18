#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    string number = "";
    int answer = 0;
    bool minus = false;

    for (int i = 0; i <= s.size() - 1; i++) {

        // 숫자인 경우. 즉, 마이너스도, 플러스도 아닌 경우
        if ((s[i] != '-') && (s[i] != '+')) {
            number += s[i];
        }

        // 부호, 혹은 마지막의 숫자인 경우
        if (s[i] == '-' || s[i] == '+' || i == s.size() - 1) {
            if (minus == true) {
                answer -= stoi(number);
            }
            else {
                answer += stoi(number);
            }
            number = "";

            // 마이너스 한 번이라도 나오면 그 뒤는 다 빼기로 간다.
            if (s[i] == '-') { minus = true; }

        }
    }

    cout << answer;


    return 0;
}
