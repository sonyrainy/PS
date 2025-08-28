#include <bits/stdc++.h>

using namespace std;


int minV = 2147000000;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int n, m;
	cin >> n >> m;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];



	sort(a.begin(), a.end());


	for (int i = 0;i<n;++i)
	{
		auto it = lower_bound(a.begin() + i, a.end(), a[i] + m);
		if (it == a.end()) continue;
		if(minV>*it-a[i]){
			minV = *it - a[i];
		}
	}

	cout << minV;
	return 0;
}