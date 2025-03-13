#include <iostream>
#include <unordered_map>

using namespace std;

int N, M, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		unordered_map<int, bool> um;
		for (int i = 0; i < N; i++)
		{
			cin >> C;
			um[C] = true;
		}
		int ans = 0;
		for (int i = 0; i < M; i++)
		{
			cin >> C;
			ans += (um.find(C) != um.end());
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/4158