#include <bits/stdc++.h>

using namespace std;

int card[500005];
int n, m;

bool f(int c) {
	int st = 0, en = n - 1;
	int mid;
	while (st<=en) {
		mid = (st + en) / 2;
		if (card[mid] < c) {
			st = mid+1;
			continue;
		}
		else if (card[mid] > c) {
			en = mid-1;
			continue;
		}
		else if (card[mid] == c) {
			return 1;
		}
	}
	return 0;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0;i<n;++i)
	{
		cin >> card[i];
	}
	sort(card, card + n);

	cin >> m;
	int tmp;
	for (int i =0;i<m;++i)
	{
		cin >> tmp;
		cout <<f(tmp)<<" ";

	}



	return 0;
}
