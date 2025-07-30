#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[20005];
int d[20005];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int V, E, st;
	cin >> V >> E >> st;

	for (int i = 1; i <= E; ++i){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}

	for (int i =1;i<=V;++i){
		d[i] = 2147000000;
	}

	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0, st });
	d[st] = 0;

	while (!pq.empty()) {

		// 시작점에서 도착하는 지점 가중치
		int w = pq.top().first;

		// 도착하는 지점
		int v = pq.top().second;

		pq.pop();

		// 미만이어야 함. 그래야지 다른 곳을 통해 갈 수 있는
		// 길도 고려할 수 있다.
		if (d[v] < w) continue;

		// u(idx), v, w
		for (auto nxt:adj[v])
		{
			if (d[nxt.first] <= d[v] + nxt.second) continue;
			d[nxt.first] = d[v] +nxt.second;
			pq.push({ d[nxt.first] , nxt.first});
		}
	}

	for (int i = 1; i <= V; ++i) {
		if (d[i] == 2147000000) { cout << "INF" << "\n"; continue; }
		cout << d[i] << "\n";

	}
	return 0;
}
