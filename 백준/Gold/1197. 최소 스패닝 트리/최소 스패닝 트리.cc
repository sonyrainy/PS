#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <bits/stdc++.h>
using namespace std;
int v, e;

int p[10005];

vector<pair<int, pair<int, int>>> edge;

int find(int x)
{
	// x가 대표 노드인 경우
	if (p[x] < 0)
		return x;
	// 경로 압축
	return p[x] = find(p[x]);
}

bool uni(int a, int b)
{
	int r_a = find(a);
	int r_b = find(b);
	if (r_a == r_b){
		return 0;
	}

	p[r_b] = r_a;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;
	for (int i = 0; i < v; ++i) {
		p[i] = -1;
	}

	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		edge.push_back({cost, {a, b}});
	}

	sort(edge.begin(), edge.end());

	int cnt = 0, ans = 0;
	for (int i = 0; i < e; i++)
	{
		int a, b, cost;
		cost = edge[i].first;
		a = edge[i].second.first;
		b = edge[i].second.second;

		// 이미 같은 그룹이면 false
		if (uni(a, b) == false) {
			continue;
		}
		else {
			ans += cost;
			cnt++;
		}

		if (cnt == v - 1)
		{
			break;
		}
	}
	cout << ans;
}