
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n>>m;
    vector<long long> v(n+1, 0);
    vector<long long> s(n+1, 0);
    vector<long long> rCnt(m + 1, 0);
    long long ans=0;

    // 구간 합 배열(벡터) 생성
    for (int i = 1; i < n+1; i++) {
        cin >> v[i];
        s[i] = s[i-1] + v[i];
        //cout << s[i] << endl; //1 3 6 7 9
        rCnt[(s[i] % m)]++;
        if (s[i] % m == 0) {
            ans++;
        }
    }

    // 조합을 활용하기
    for (int i = 0; i < m; i++) {
        ans += (rCnt[i] * (rCnt[i] - 1)) / 2;
    }

    cout << ans;
    return 0;
}