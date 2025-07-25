#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> vec[1005];
bool visited[1005];
int cnt = 0;

void DFS(int node) {
	visited[node] = true;
	for (int k : vec[node]) {
		if (visited[k]) continue;
		DFS(k);
	}

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		if (visited[i]) continue;
		DFS(i);
		++cnt;
	

	}
	cout << cnt;


	return 0;
}
