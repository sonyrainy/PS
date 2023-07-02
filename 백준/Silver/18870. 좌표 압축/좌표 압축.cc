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

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = a[i];

    }
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (int i =0; i < a.size(); i++) {
        cout << lower_bound(c.begin(), c.end(), a[i]) - c.begin() << " ";
    }

    return 0;
}