#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<vector<int>> vec(n + 1);
	vector<int> par(n + 1, 0);

	int a, b;

	// vec에 연결된 노드들 다 정리
	for (int i = 0; i < n-1; ++i) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);

		//미리 넣어버리면 전체
		//수에 대해서 q.push가 막혀버린다.
		//if (a == 1) {
		//	par[b] = 1;
		//}
		//else if (b == 1) {
		//	par[a] = 1;
		//}
	}

	queue<int> q;
	q.push(1);


	while (!q.empty()) {
		int a = q.front(); q.pop();
		for (int cur : vec[a]) {

			if (par[cur] != 0) {
				continue;
			} 

			par[cur] = a;
			q.push(cur);

		}
	}

	for (int i = 2; i <= n; i++) {
		cout << par[i] << "\n";
	}
}