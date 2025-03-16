#include <iostream>
#include <list>

using namespace std;

list<int> L;

int N, C;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		auto iter = L.begin();
		cin >> C;
		while (C--) iter++;
		L.insert(iter, i + 1);
	}
	auto iter = --L.end();
	for (; iter != L.begin(); iter--)
		cout << *iter << " ";
	cout << *iter << '\n';
}

// https://www.acmicpc.net/problem/2605