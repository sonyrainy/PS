#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, x, y;
	cin >> a >> b;
	cin >> x >> y;

	if (a == 0) {
		if (x == 0 &&  y <= b) cout << 3 << '\n';
		else cout << 1 << '\n';
		return 0;
	}
	if (b == 0) {
		if (y == 0 &&  x <= a) cout << 3 << '\n';
		else cout << 1 << '\n';
		return 0;
	}

	cout << 2 << '\n';
	return 0;
}