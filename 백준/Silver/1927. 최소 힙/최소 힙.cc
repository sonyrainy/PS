#include <bits/stdc++.h>

using namespace std;
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, cmp> pq;

	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

	return 0;
}