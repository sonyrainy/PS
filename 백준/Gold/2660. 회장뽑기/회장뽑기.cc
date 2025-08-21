#include <bits/stdc++.h>

using namespace std;
int member_soo, a=0, b=0;
vector<vector<int>> vec(55);
int cnt_arr[55];
bool visited[55];
int score[55];
queue<int> q;

void bfs(int cur) {
	int st = cur;
	q.push(cur);
	fill(visited, visited + 54, 0);
	fill(cnt_arr, cnt_arr + 54, 0);

	visited[cur] = 1;


	while (!q.empty()) {
		cur = q.front();
		q.pop();
		for (int nxt:vec[cur])
		{
			if (visited[nxt] == 1) continue;
			cnt_arr[nxt] = cnt_arr[cur] + 1;
			visited[nxt] = 1;
			q.push(nxt);
		}
	}
	int mx = -2147000000;
	for (int i =1;i<=member_soo;++i)
	{
		mx = max(mx, cnt_arr[i]);
	}
	score[st] = mx;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> member_soo;

	while (1) {
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int cur=1;cur<= member_soo;++cur)
	{
		bfs(cur);
	}
	
	int min_e = *min_element(score + 1, score + member_soo);

	int cnt = 0;
	
	vector<int> cand;
	for (int i = 1;i<=member_soo;++i)
	{
		if (min_e == score[i]) { 
			++cnt; 
			cand.push_back(i);
		}
	}
	cout << min_e << " "<< cnt<<"\n";

	for (int c : cand) {
		cout << c << " ";
	}


	return 0;
}