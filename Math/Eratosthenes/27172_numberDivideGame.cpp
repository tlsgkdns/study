#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> um;
int N, X[100001], ans[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
		um.insert({ X[i], i });
	}
	for (int i = 0; i < N; i++)
	{
		for (int x = X[i] * 2; x <= 1000000; x += X[i])
		{
			if (um.find(x) != um.end())
			{
				ans[um[x]]--;
				ans[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++) cout << ans[i] << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/27172