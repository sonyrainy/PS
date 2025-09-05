#include <bits/stdc++.h>
using namespace std;

struct Item {
	int val;
	int idx;
};

struct cmp {
	bool operator()(Item& a, Item& b)  {
		if (a.val != b.val) return a.val < b.val;
		return a.idx < b.idx;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<Item> a(N);
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		a[i] = { x, i + 1 };
	}

	sort(a.begin(), a.end(), cmp());

	vector<long long> pSum(N + 1, 0);

	// 한칸 씩 앞으로 가면서 구간 합이 되어줄 값들 추가.
	for (int i = N - 1; i >= 0; --i) {
		pSum[i] = pSum[i + 1] + a[i].val;
	}


	long long bestScore = -2147000000;
	int bestL = 0;
	
	for (int L = 0; L < N; ++L) {
		long long score = pSum[L] + a[L].val + a[N - 1].val;
		if (score > bestScore) {
			bestScore = score;
			bestL = L;
		}
	}

	cout << (N - bestL) << "\n";

	for (int i = bestL; i < N; ++i) {
		cout << a[i].idx << " ";
	}
	return 0;
}
