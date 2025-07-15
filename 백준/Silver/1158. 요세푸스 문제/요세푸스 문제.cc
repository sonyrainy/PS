#include <iostream>
#include <list>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	list<int> lis;
	for (int i = 1; i <= n; ++i) lis.push_back(i);

	auto iter = lis.begin();          // 채운 뒤에 초기화
	cout << '<';

	while (!lis.empty()) {

		// K-1번만 이동
		for (int i = 1; i < k; ++i) {
			++iter;
			if (iter == lis.end()) iter = lis.begin();
		}

		cout << *iter;

		// list의 erase()는 다음 iterator를 반환한다.
		iter = lis.erase(iter);
		if (iter == lis.end()) iter = lis.begin();

		if (lis.empty()) cout << ">";
		else              cout << ", ";
	}
	return 0;
}
