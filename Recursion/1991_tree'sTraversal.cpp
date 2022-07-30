#include <iostream>

using namespace std;

int N;
char C, L, R;
pair<char, char> tree[26];

void preOrder(int now)
{
	cout << (char)(now + 'A');
	if (tree[now].first != '.')
		preOrder(tree[now].first - 'A');
	if (tree[now].second != '.')
		preOrder(tree[now].second - 'A');
}
void inOrder(int now)
{
	if (tree[now].first != '.')
		inOrder(tree[now].first - 'A');
	cout << (char)(now + 'A');
	if (tree[now].second != '.')
		inOrder(tree[now].second - 'A');
}
void postOrder(int now)
{
	if (tree[now].first != '.')
		postOrder(tree[now].first - 'A');
	if (tree[now].second != '.')
		postOrder(tree[now].second - 'A');
	cout << (char)(now + 'A');
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> C >> L >> R;
		tree[C - 'A'] = { L, R };
	}
	preOrder(0);
	cout << '\n';
	inOrder(0);
	cout << '\n';
	postOrder(0);
	cout << '\n';
}

// https://www.acmicpc.net/problem/1991