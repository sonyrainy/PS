#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include <cmath>

using namespace std;
int pArr[1001], lArr[1001];
char cArr[1001];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> pArr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> lArr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> cArr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (pow(pArr[i] - pArr[j], 2) <= pow(lArr[i] + lArr[j], 2)) {
				if (cArr[i] != cArr[j]) {
					cout << "YES" << "\n";
					cout << i+1 << " " << j+1 << "\n";
					return 0;
				}
				else {
					continue;
				}
			}
		}

	}
	cout << "NO" << "\n";
	return 0;
}