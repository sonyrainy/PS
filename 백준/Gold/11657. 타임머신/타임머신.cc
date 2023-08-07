#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
int n, m;
int INF = 2147000000;

// 간선 정보를 저장하는 벡터
vector<pair<pair<int, int>, int>> a;

// 최단 거리를 저장하는 벡터
vector<long long> d(501);
// 초기화는 선언 시 자동으로 이뤄지고, 별도의 초기화가 필요하지 않다.
bool mCycle = false;

// 벨만포드 실행 함수
void bellman_ford() {

    for (int i = 1; i <= n; i++) { 
        d[i] = INF; 
    }

    d[1] = 0;

    // n-1번 반복 적용한다.
    // 1, 2, 3번 노드가 있다고 생각했을 때 1에서 3
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {

            int startN = a[j].first.first;
            int endN = a[j].first.second;
            int dist = a[j].second;
            
            // 방문하지 않은 상태라면, 넘어간다.
            if (d[startN] == INF) { continue; }
            if (d[endN] > d[startN] + dist) {
                d[endN] = d[startN] + dist;
            }
        }
    }

    // 한 번 더 사용하였을 때, 갱신된다면 그 부분은 음의 사이클이 존재하는 부분이다.
        for (int i = 0; i < m; i++) {

            int startN = a[i].first.first;
            int endN = a[i].first.second;
            int dist = a[i].second;

            if (d[startN] == INF) { continue;}

            // 갱신된다면 mCycle이 존재한다는 것이 된다.
            if (d[endN] > d[startN] + dist) {
                mCycle = true;
            }
        }
 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
   
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        a.push_back(make_pair(make_pair(start, end), cost));
    }


    bellman_ford();

    // 음수 사이클이 나오면 무의미해진다.
    if (mCycle == true) {
        cout << -1 << "\n";
    }
    else {
        // 1번 도시에서 2~n번째 도시로 가는 경우를 다 출력한다.
        // 방문하지 않은 (끊겨있는) 부분에 대해서는 -1을 출력한다.
        for (int i = 2; i <= n; i++) {
            if (d[i] == INF) { cout << -1 << "\n"; }
            else { cout << d[i] << "\n"; }
        }
    }
    return 0;
}
