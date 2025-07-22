#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> uni(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        uni[i] = a[i];

    }
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());
    for (int i =0; i < a.size(); i++) {
        cout << lower_bound(uni.begin(), uni.end(), a[i]) - uni.begin() << " ";
    }

    return 0;
}