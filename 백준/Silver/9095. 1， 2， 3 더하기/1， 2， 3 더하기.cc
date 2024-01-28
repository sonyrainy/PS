#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    vector<int> v(12);
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;

    for (int i = 4; i < 11; i++) {
        v[i] = v[i - 1] + v[i - 2] + v[i - 3];
    }

    for (int i = 0; i < T; i++) {
        int c;
        cin >> c;
        cout << v[c]<<"\n";
    }

    return 0;
}