#include <bits/stdc++.h>

using namespace std;
int l, r;
struct cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	priority_queue<int> L;
	priority_queue<int, vector<int>, cmp> R;

	int n, x;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (L.size() == R.size()) L.push(x);
		else R.push(x);

		if (!R.empty()&&R.top() < L.top()) {
			int a = L.top();
			L.pop();
			int b = R.top();
			R.pop();
			L.push(b);
			R.push(a);
		}

		cout << L.top() << "\n";

	}

	return 0;
}