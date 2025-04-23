#include <iostream>
#include <stdio.h>

using namespace std;

int a[101];
int main(void) {
	fill(a, a + 101, 0);
	string c;

	cin >> c;

	for (int i = 0; i < c.size(); i++) {
		int temp = 'a';
		a[c[i] - temp]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << a[i] << " ";
	}

}