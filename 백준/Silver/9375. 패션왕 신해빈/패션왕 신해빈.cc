#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; ++i)
	{
		int n;
		cin >> n;
		unordered_map<string, int> type_map;

		for (int j =0;j<n;++j)
		{
			
			string s1, type;
			cin >> s1 >> type;

			// 같은 타입 발견하면, value에 +1 더한다.
				type_map[type] = type_map[type] + 1;

		}

		long long ans = 1;
		//type_map의 키들 각각의 (value 개수+1)를 센다.
		//전부 곱하고 1을 뺀다.
		for (auto &i:type_map)
		{
			ans = ans * (i.second + 1);
		}

		ans = ans - 1;

		cout << ans << "\n";

	}


	return 0;
}