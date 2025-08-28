#include <bits/stdc++.h>

using namespace std;



int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, s;
	cin >> n >> s;

	vector<int> a(n);
	for (int i =0;i<n;++i) cin >> a[i];
	
	int en = 0;
	int minV = 2147000000;

	int sum = a[0];
	for (int st = 0;st<n;++st)
	{
		while (en < n && sum < s) { 
			++en; 
			if (en != n) sum += a[en];

		}
		if (en == n) break;
		minV = min(minV, en - st + 1);
		sum -= a[st];

	}
	if (minV == 2147000000) minV = 0;
	cout << minV;

	return 0;
}