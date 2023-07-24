#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {

        // a,b의 끝 값이 같으면, 시작 시간이 더 이른 것이 정렬
        // 앞의 것이 작을 때 true니까 조건은 정렬 시, true가 되도록 만들면 된다.
        return a.first < b.first;
    }

    // 일반적인 다른 경우에는, 끝나는 시각이 작은 것이 먼저 정렬
    else { return a.second< b.second; }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, cnt=0, stdTime=0;
    cin >> N;
    vector<pair<int, int>> p(N);
    for (int i = 0; i < N; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(), compare);
    
    for (int i = 0; i < N; i++) {
      if (stdTime <= p[i].first) {
            cnt++;
            stdTime = p[i].second;
        }
    }
    cout << cnt;

}