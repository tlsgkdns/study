#include <iostream>
#include <list>
#include <cstring>
using namespace std;
list<int> L;
int K, M, R;
bool v[101];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K;
	for (int i = 1; i <= K; i++) L.push_back(i);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> R;
		memset(v, false, sizeof(v));
		auto iter = L.begin();
		int s = L.size();
		for (int i = 1; i <= s; i++)
		{
			if (i % R == 0)
				iter = L.erase(iter);
			else
				++iter;
		}
	}
	for (auto iter = L.begin(); iter != L.end(); iter++)
		cout << *iter << '\n';
}

// https://www.acmicpc.net/problem/10104