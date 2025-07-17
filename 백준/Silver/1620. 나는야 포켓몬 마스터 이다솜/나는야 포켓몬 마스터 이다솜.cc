#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <unordered_map>
#include <string>
#include <cctype>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	unordered_map<int, string> dogam_number;
	unordered_map<string, int> dogam_name;

	string name;

	for (int i = 1; i <= n; i++) {

		cin >> name;
		dogam_number.insert({ i, name });
		dogam_name.insert({ name, i });


	}

	int poke_name;
	string poke_num;

	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;
		if (isdigit(input[0])) {
			cout << dogam_number[stoi(input)] << "\n";
		}
		else {
			cout << dogam_name[input] << "\n";
		}
	}


}