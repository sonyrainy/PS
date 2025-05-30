#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> status(N);
    int cnt = 0;
    bool conti = false;

    // 초기 상태 확인
    for (int i = 0; i < N; i++) {
        cin >> status[i];
        if (status[i] == 1 && !conti) {
            cnt++;
            conti = true;
        }
        else if (status[i] == 0) {
            conti = false;
        }
    }

    // 명령 처리
    for (int i = 0; i < M; i++) {
        int trial;
        cin >> trial;
        if (trial == 0) {
            cout << cnt << "\n";  // 연속된 1의 개수 출력
        }
        else {
            int index;
            cin >> index;
            index--;

            if (status[index] == 1) continue;  // 이미 1이면 아무 일도 하지 않음

            status[index] = 1;  // 해당 인덱스를 1로 설정

            // 첫 번째 인덱스일 경우
            if (index == 0) {
                if (status[index + 1] == 0) cnt++;
            }
            // 마지막 인덱스일 경우
            else if (index == N - 1) {
                if (status[index - 1] == 0) cnt++;
            }
            // 중간 인덱스일 경우
            else {
                if (status[index - 1] == 0 && status[index + 1] == 0) {
                    cnt++;  // 양 옆이 0이면 새로운 연속된 1 구간 추가
                }
                else if (status[index - 1] == 1 && status[index + 1] == 1) {
                    cnt--;  // 양 옆이 1이면 연속된 1 구간 감소
                }
            }
        }
    }

    return 0;
}
