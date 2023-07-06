
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
    vector<vector<int>> v(n+1, vector<int>(n+1, 0));
    vector<vector<int>> s(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            cin >> v[i][j];
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + v[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
        cout << result << "\n";
    }



    return 0;
}