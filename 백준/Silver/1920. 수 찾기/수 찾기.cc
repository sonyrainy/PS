#include <bits/stdc++.h>

using namespace std;
int arr[100000];
int n;

void BinarySearch(int num) {
	int start = 0, end = n-1;
	
	while (start <= end) {
		int mid = (start + end) / 2;

		if (arr[mid] == num) {
			cout << 1 << "\n";
			return;
		}
		else if (arr[mid] < num) {
			start = mid + 1;
			continue;
		}
		else {
			end = mid - 1;
			continue;
		}
	}
	cout << 0 << "\n";

}

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
		BinarySearch(num);
	}
	


	return 0;
}