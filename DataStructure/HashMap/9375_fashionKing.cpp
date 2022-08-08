#include <iostream>
#include <unordered_map>
using namespace std;

int T, N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		string s1, s2;
		unordered_map<string, int> um;
		for (int n = 0; n < N; n++)
		{
			cin >> s1 >> s2;
			um[s2]++;
		}
		int ans = 1;
		for (pair<string, int> p : um)
			ans *= (p.second + 1);
		cout << ans - 1 << '\n';
	}
}

// https://www.acmicpc.net/problem/9375