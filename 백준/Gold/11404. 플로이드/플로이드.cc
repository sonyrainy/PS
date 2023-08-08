
#include <algorithm>
#include <iostream>
#include <vector>

#define D_SIZE 101
#define INF 2147000000

using namespace std;
int n, m;

vector<vector<int>> d(D_SIZE, vector<int>(D_SIZE, 0));
//int d[101][101];

void floyd_warshall() {
    // 가장 바깥에 거쳐가는 k를 둔다.
    for (int k = 1; k <= n; k++) {
        for (int s = 1; s <= n; s++) {
            for (int e = 1; e <= n; e++) {
                if (d[s][k] != INF && d[k][e] != INF) {
                    // k를 거쳐간 애가 지금의 d[s][e]보다 작으면 업데이트한다.
                    d[s][e] = min(d[s][e], d[s][k] + d[k][e]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    // 모든 부분 무한대로 초기화, 자기 자신으로 가는 부분은 0으로 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                d[i][j] = 0;
            }
            else {
                d[i][j] = INF;
            }
        }

    }


    // 직접적으로 연결되어 있는 경우 입력 받아서 연결, 안되어있으면 INF 유지
    for (int i = 1; i <= m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        d[start][end] = min(d[start][end], cost);
    }

    floyd_warshall();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == INF) {
                cout << 0 << " ";
            }
            else {
                cout << d[i][j] << " ";
            }
        } cout << "\n";

    }


    return 0;
}
