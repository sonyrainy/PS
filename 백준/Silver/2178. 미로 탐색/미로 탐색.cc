#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>

using namespace std;

int Min = 2147000000;
int n, m;
//int map[n][m], visited[n][m];
//map의 값을 받을 때, 숫자가 붙은 상태로 받기 때문에 char로 받아 하나하나 뜯는다.

//vector<vector<char>> map(n,vector<char>(n, '0'));
//vector<vector<int>> visited(n, vector<int>(m, 0));
char map[101][101];

//방문 여부용
int visited[101][101];

//방문 횟수용
int check[101][101];

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0 , -1 };

void BFS(int x, int y) {
    int xx, yy;
    visited[x][y] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    // 큐가 비어있을 때까지 반복
    while (q.empty() == false) {
        x = q.front().first;
        y = q.front().second;

        q.pop();
        for (int i = 0; i < 4; i++) {
            xx = x + dx[i];
            yy = y + dy[i];

            // 미로의 내부 안에서
            if (xx >= 0 && xx < n && yy >= 0 && yy < m) {

                // 방문된 적 없고, 지나갈 수 있는 곳이라면
                if (visited[xx][yy] == 0 && map[xx][yy] == '1') {
                    check[xx][yy] = check[x][y] + 1;
                    visited[xx][yy] = 1;
                    q.push(make_pair(xx, yy));
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }

    BFS(0, 0);

    cout << check[n-1][m-1]+1;

    return 0;
}
