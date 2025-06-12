#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	list<char> L;
	for (auto c : s) L.push_back(c);
	auto cursor = L.end();

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if(cursor != L.begin())	cursor--;
		}
		//L.end()는 L의 가장 끝 더미노드(없을 수도 있긴 함.)의 위치를 가리킨다.
		//정확하게는 list의 마지막 data의 다음 위치를 가리키는 포인터 같은 객체이다.
		else if (cmd == 'D') {
			if (cursor != L.end())	cursor++;
		} 
		else if (cmd == 'B') {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
		else {
			char temp;
			cin >> temp;
			L.insert(cursor, temp);
		}
	}
	for (auto cursor : L) {
		cout << cursor ;
	}
}