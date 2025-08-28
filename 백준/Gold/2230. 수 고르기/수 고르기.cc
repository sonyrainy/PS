#include <bits/stdc++.h>

using namespace std;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	int minV = 2147000000;

	cin >> n >> m;
	vector<int> a(n);

	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	int en = 0;
	for (int st = 0; st < n; ++st) {
		while (en < n && a[en] - a[st] < m) ++en;
		if (en == n) break;
		minV = min(minV, a[en] - a[st]);
	}
	cout << minV;


	return 0;
}