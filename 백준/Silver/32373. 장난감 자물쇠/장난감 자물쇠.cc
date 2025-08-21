#include <bits/stdc++.h>
using namespace std;

vector<string> keyboard(4);


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<vector<int>> g(k);
	for (int i = 0; i < n; ++i) g[i % k].push_back(a[i]);

	for (int r = 0; r < k; ++r) sort(g[r].begin(), g[r].end());

	vector<int> idx(k, 0);
	for (int i = 0; i < n; ++i) a[i] = g[i % k][idx[i % k]++];

	cout << (is_sorted(a.begin(), a.end()) ? "Yes" : "No");

	return 0;
}