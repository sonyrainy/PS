
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int, string> p1, pair<int, string> p2) {
    return p1.first < p2.first; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n>>m;
    vector<int> v(n+1);
    vector<int> s(n+1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
 
        s[i] = s[i - 1] + v[i];
    }

    for (int i =0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << s[b] - s[a-1]<<"\n";

    }

    return 0;
}