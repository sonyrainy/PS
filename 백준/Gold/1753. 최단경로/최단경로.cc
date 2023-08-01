#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
int INF = 2147000000;

// 간선 정보를 저장하는 벡터
vector<pair<int, int>> a[300001];

// 최단 거리를 저장하는 벡터
vector<int> d(20001);

// 다익스트라 실행 함수
void dijkstra(int startN) {

    // 시작점에서 시작점으로의 최소 거리는 0
    d[startN] = 0;

    // min heap 구조, 더 작은 값을 기준으로 최상단 노드를 만들도록 한다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 출발 노드의 정보를 우선순위 큐에 넣는다.
    pq.push(make_pair(0, startN));
    while (pq.empty()==false) {

        // 기준 점부터 가장 최소 거리 노드의 index
        int current = pq.top().second;

        // 기준 점부터 가장 최소 거리 노드의 값
        int distance = pq.top().first;
        pq.pop();

        // 최단 거리가 아닌 경우 스킵
        if (d[current] < distance) continue;

        for (int i = 0; i < a[current].size(); i++) {

            // 선택된 노드의 인적노드
            int nextIndex = a[current][i].first;

            // 선택된 노드를 거쳐서 인접 노드로 가는 거리
            int nextDistance = distance + a[current][i].second;

            // 기존 최소 비용보다 더 작다면 교체
            if (nextDistance < d[nextIndex]) {
                d[nextIndex] = nextDistance;

                // 그렇게 새롭게 갱신된 값을 넣어준다.
                pq.push(make_pair(nextDistance, nextIndex));
            }
        }

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    int startN;
    cin >> startN;

 
    for (int i = 1; i <= v; i++) {
        d[i] = INF;
    }

    for (int i = 0; i < e; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        a[start].push_back(make_pair(end, cost));
    }


    dijkstra(startN);

    for (int i = 1; i <= v; i++) {
        if (d[i] == INF) {
            cout << "INF" << '\n';
        }
        else {
            cout << d[i] << '\n';
        }
    }

    return 0;
}
