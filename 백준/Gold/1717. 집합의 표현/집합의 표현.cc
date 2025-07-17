#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;

int p[1000005];

// 각각의 root가 같은지를 찾기 위한 find()
int find(int a){
	if (p[a] == a) {
		return a;
	}

	return p[a] = find(p[a]);

}

void uni(int a, int b) {
	int a_r = find(a);
	int b_r = find(b);

	if (a_r == b_r) { return; }
	p[b_r] = a_r;
	

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, f;
	cin >> n >> m;
	for (int i = 1;i<=n;i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < m; ++i) {
		cin >> f;
		int a, b;
		cin >> a >> b;
		if (f == 1) {
			int r_a, r_b;
			r_a = find(a);
			r_b = find(b);
			if (r_a == r_b) { cout << "yes" << "\n"; }
			else { cout << "no" << "\n"; }
		}
		else {
			uni(a, b);
		}
	}

}