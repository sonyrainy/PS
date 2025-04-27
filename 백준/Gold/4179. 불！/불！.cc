#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <queue>
//메모리 줄이겠다고 큐 하나로 가려다가 대가리 깨짐.ㅇㅇ


using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

char arr[1001][1001];
int jVisit[1001][1001];
int fVisit[1001][1001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> r >> c;
    queue<pair<int, int>> jQ;
    queue<pair<int, int>> fQ;

    string s;


    for (int i = 0; i < r; i++) {
        cin >> s;
        for (int j = 0; j < c; j++) {
            arr[i][j] = s[j];
            if (s[j] == 'J') {
                jVisit[i][j] = 1;
                jQ.push({ i, j });
                if (i == 0 || i == r - 1 || j == 0 || j == c - 1) {
                    cout << 1 << '\n';
                    return 0;
                }

            }
            else if (s[j] == 'F') {
                fVisit[i][j] = 1;
                fQ.push({ i, j });
            }
        }
    }

    while (!fQ.empty()) {
        int curX = fQ.front().X;
        int curY = fQ.front().Y;
        fQ.pop();

        for (int i = 0; i < 4; i++) {
            int x, y;
            x = curX + dx[i];
            y = curY + dy[i];

            if (x < 0 || x >= r || y < 0 || y >= c) continue;
            if (arr[x][y] == '#') continue;

            // 처음 가는 곳이면 + 1
            if (fVisit[x][y] == 0) {
                fVisit[x][y] = fVisit[curX][curY] + 1;
                fQ.push({ x, y });
            }

            // 다른 불로 인해서 간 곳인데, 지금게 더 빠르게 퍼진 것이라면?
            else if (fVisit[x][y] > fVisit[curX][curY] + 1) {
                fQ.push({ x, y });
                fVisit[x][y] = fVisit[curX][curY] + 1;
            }
        }
    }


    while (!jQ.empty()) {
        int curX = jQ.front().X;
        int curY = jQ.front().Y;
        jQ.pop();

        for (int i = 0; i < 4; i++) {
            int x, y;
            x = curX + dx[i];
            y = curY + dy[i];


            if (x < 0 || x >= r || y < 0 || y >= c) continue;
            if (arr[x][y] == '#') continue;

            // 불이 있는 곳이거나 지훈이보다 더 늦게 온 곳
            if (fVisit[x][y] != 0 && fVisit[x][y] <= jVisit[curX][curY] + 1) continue;
            
            // 지훈이가 이미 들른 곳
            if (jVisit[x][y] != 0) continue;
            
            // 나갈 수 있게 된 지점이라면?
            if (x == 0 || x == r - 1 || y == 0 || y == c - 1) {
                cout << jVisit[curX][curY] +1 << "\n";
                return 0;
            }

            jVisit[x][y] = jVisit[curX][curY] + 1;
            jQ.push({ x, y });

        }
    }

    cout << "IMPOSSIBLE" << "\n";


    return 0;
}
