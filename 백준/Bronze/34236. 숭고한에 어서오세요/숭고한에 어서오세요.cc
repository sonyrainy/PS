#include <bits/stdc++.h>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> x;
	for (int i = 0;i<n;++i)
	{
		
		int t;
		cin >> t;
		x.push_back(t);
	}


	cout << x[n-1] + (x[n-1]-x[n-2]);
	return 0;
}