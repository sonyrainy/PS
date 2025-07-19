#include <bits/stdc++.h>

using namespace std;

struct Cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}

		return abs(a) > abs(b);
		

	}
};

	int main() {
		int n, x;
		priority_queue<int, vector<int>, Cmp> q;
		vector<int> v;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x == 0) {
				if (q.empty()) {
					// 큐가 비어있을 때 0을 출력
					v.push_back(0);
				}
				else {
					v.push_back(q.top()); // 가장 작은 원소 출력
					q.pop(); // 제거
				}
			}
			else {
				q.push(x); // 원소 추가
			}
		}

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n'; // 정답 출력
		}

		return 0;
	}

