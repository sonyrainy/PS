#include <bits/stdc++.h>

using namespace std;

struct Cmp {
	bool operator()(int a, int b) {
		return a > b;
	}
};

int main() {
		int n, sum = 0;
		priority_queue<int, vector<int>, Cmp> q;

		cin >> n;

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			q.push(num);
		}

		int a, b;
		while (q.size() != 1) {
			a = q.top();
			q.pop();
			b = q.top();
			q.pop();
			sum += a + b;
			q.push(a+b);

		}

		cout << sum;


		return 0;
}
