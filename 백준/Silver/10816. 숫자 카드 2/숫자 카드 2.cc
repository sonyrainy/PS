#include <bits/stdc++.h>

using namespace std;
int arr[500005];
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int m;
	cin >> m;

	int num;
	for (int i = 0; i < m; ++i) {
		cin >> num;
		cout << upper_bound(arr, arr + n, num) - lower_bound(arr, arr + n, num) << " ";
	}
	


	return 0;
}