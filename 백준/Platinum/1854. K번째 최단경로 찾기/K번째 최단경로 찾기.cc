#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
int INF = 2147000000;
int k;
// 간선 정보를 저장하는 벡터
vector<pair<int, int>> a[1001];

// 최단 거리를 저장하는 벡터
// vector<int> d(20001);
priority_queue<int> d[1001];
// 초기화는 선언 시 자동으로 이뤄지고, 별도의 초기화가 필요하지 않다.


// 다익스트라 실행 함수
void dijkstra(int startIndex) {

    // min heap 구조, 더 작은 값을 기준으로 최상단 노드를 만들도록 한다.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 시작점에서 시작점으로의 최소 거리는 0
    d[1].push(0);

    // 출발 노드의 정보를 우선순위 큐에 넣는다.
    pq.push(make_pair(0, startIndex));
     
    while (pq.empty()==false) {

        // 기준 점부터 가장 최소 거리 노드의 index
        int current = pq.top().second;

        // 기준 점부터 가장 최소 거리 노드의 값
        int distance = pq.top().first;

        pq.pop();

        for (int i = 0; i < a[current].size(); i++) {

            // 선택된 노드의 인적노드
            int nextIndex = a[current][i].first;

            // 선택된 노드를 거쳐서 인접 노드로 가는 거리
            int nextDistance = distance + a[current][i].second;
            //int nextDistance =   a[current][i].second;


            // 여기서 달라지는데, 
            // 최소 거리에 대한 저장 공간을 우선순위 큐로 만들었으니까,
            // k번째의 값을 계속 갱신하도록 한다.
            if (d[nextIndex].size() < k) {
                d[nextIndex].push(nextDistance);

                // 그렇게 새롭게 갱신된 값을 넣어준다.
                pq.push(make_pair( nextDistance, nextIndex));
            }
            else if (d[nextIndex].top() >  nextDistance) {
                d[nextIndex].pop();//해당 경로에서 k번째인 경우를 삭제시킴
                d[nextIndex].push(nextDistance);
                pq.push(make_pair(nextDistance, nextIndex));
            }
        }

    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    //int k;
    cin >> n >> m >> k;
   
    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        a[start].push_back(make_pair(end, cost));
    }


    dijkstra(1);//dijkstra(0);

    for (int i = 1; i <= n; i++) {
        if (d[i].size() < k) {
            cout << "-1" << "\n";
        }
        else {
            cout << d[i].top() << "\n";
        }
    }

    return 0;
}
