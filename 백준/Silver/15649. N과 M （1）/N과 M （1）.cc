#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int is_used[10];

void func(int cnt) {
	// m개 골랐으면 출력
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";

		}
		cout << "\n";

		return;

	}


	for (int i = 1; i <= n; i++) {
		// i가 사용되지 않았다면 사용하자.
		if (is_used[i] == 0) {
			arr[cnt] = i;
			is_used[i] = 1;
			func(cnt + 1);
			is_used[i] = 0;
		}

	}
}


int main() {
	cin >> n  >> m;
	func(0);
	return 0;

}
