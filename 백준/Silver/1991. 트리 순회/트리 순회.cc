#include <iostream>
#include <map>
using namespace std;

map<char, pair<char, char>> tree;

void preorder(char node)
{
	cout << node;
	if (tree[node].first != '.')
		{preorder(tree[node].first);}
	if (tree[node].second != '.')
		{preorder(tree[node].second);}
}

void inorder(char node)
{
	if (tree[node].first != '.')
		{inorder(tree[node].first);}
	cout << node;
	if (tree[node].second != '.')
		{inorder(tree[node].second);}
}

void postorder(char node)
{
	if (tree[node].first != '.')
		{postorder(tree[node].first);}
	if (tree[node].second != '.')
		{postorder(tree[node].second);}
	cout << node;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	char node;
	while (n--)
	{
		cin >> node;
		cin >> tree[node].first >> tree[node].second;
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
}