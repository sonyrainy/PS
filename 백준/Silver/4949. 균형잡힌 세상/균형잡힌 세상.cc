#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string s;
		getline(cin, s);
		if (s == ".") break;
		bool sc = 0;
		stack<char> k;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[') {
				k.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == ']') {
				if (k.size() == 0) {
					sc = true;
					break;
				}

				if (k.top() != '(' && s[i] == ')') {
					break;
				}
				else if (k.top() != '[' && s[i] == ']') {
					break;
				}

				if ((k.top() == '(' && s[i] == ')') || (k.top() == '[' && s[i] == ']')) {
					k.pop();
				}
			}

		}
		if (k.size() == 0) {
			if (sc == true) {
				cout << "no" << "\n";

			}
			else {
				cout << "yes" << "\n";
			}
		}
		else {
			cout << "no" << "\n";
		}
		


	}


}