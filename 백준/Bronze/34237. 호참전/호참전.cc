#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N), B(N), S(N); 
    for (int i = 0; i < N; ++i) {
        cin >> A[i] >> B[i];
        S[i] = A[i] + B[i];
    }

    for (int j = 0; j < M; ++j) {
        int g, x, y;
        cin >> g >> x >> y;

        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] >= x && B[i] >= y && S[i] <= g) ++cnt;
        }
        cout << cnt << "\n";
    }
    return 0;
}
