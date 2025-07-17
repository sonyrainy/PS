#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <unordered_set>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	unordered_set<string> s;
	string name;
	string e_or_l;
	
	for (int i = 0; i < n; ++i) {
		
		cin >> name >> e_or_l;
		if (e_or_l == "enter") {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}

	vector<string> vec;
	for (string name : s) {
		vec.push_back(name);
	}
	sort(vec.begin(), vec.end(), greater<>());

	for (string name : vec) {
		cout << name << "\n";
	}

}