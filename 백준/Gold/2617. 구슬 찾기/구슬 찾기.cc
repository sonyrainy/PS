#include <bits/stdc++.h>

using namespace std;
int member_soo, a=0, b=0;
vector<vector<int>> vec(55);
int cnt_arr[55];
int score[55];
queue<int> q;
vector<vector<int>> h_vec(105);
vector<vector<int>> l_vec(105);
int n, m;
int vis[105];


int l_f(int s) {
	fill(vis, vis + n+1, 0);
	q.push(s);
	vis[s] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		//l_vec에 값이 있으면 넣어봐야지.
		for (int nxt : l_vec[cur])
		{
			if (vis[nxt]) continue;
			++cnt;
			vis[nxt] = 1;
			q.push(nxt);
		}
	}

	return cnt;
}
int h_f(int s) {
	fill(vis, vis + n+1, 0);
	q.push(s);
	vis[s] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		//l_vec에 값이 있으면 넣어봐야지.
		for (int nxt : h_vec[cur])
		{
			if (vis[nxt]) continue;
			++cnt;
			vis[nxt] = 1;
			q.push(nxt);
		}
	}

	return cnt;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		//u가 더 무겁다.
		h_vec[v].push_back(u);
		l_vec[u].push_back(v);
	}

	int cnt = 0;
	// 찾는게 필요함.
	for (int i =1;i<=n;++i)
	{
		if ((l_f(i) >= (n + 1) / 2) || (h_f(i)
			>= (n+1)/2)) ++cnt;
	}
	
	cout << cnt;

	return 0;
}