#include <bits/stdc++.h>

using namespace std;
int m, n;
int cnt = 0;
int arr[105][10005];

void change(int a[]) {
	vector<int> b(a, a + n);

	sort(b.begin(), b.end());

	b.erase(unique(b.begin(), b.end()), b.end());

	for (int i = 0; i < n; ++i) {
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
	}
	
}

void cmp(int a[], int b[]) {
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) return;
	}
	++cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m>>n;


	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0;i<m;++i)
	{
		change(arr[i]);
	}

	
	for (int i = 0; i < m-1; ++i) {
		for (int j = i+1; j < m; ++j) {
			cmp(arr[i], arr[j]);
		}
	}
	cout << cnt;


	return 0;
}