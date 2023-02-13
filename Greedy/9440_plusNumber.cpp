#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N, P[15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	while (true)
	{
		cin >> N;
		if (N == 0) break;
		string num[2] = { "", "" };
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> P[i];
			P[i] = -P[i];
		}
		sort(P, P + N);
		for (int i = 0; i < N - 1; i++)
			num[i % 2].push_back(-P[i] + '0');
		num[1].push_back(-P[N - 1] + '0');
		for (int i = 0; i < 2; i++)
		{
			int idx = num[i].size() - 1;
			while (num[i][idx] == '0') --idx;
			if (idx < num[i].size() - 1) swap(num[i][num[i].size() - 1], num[i][idx]);
			reverse(num[i].begin(), num[i].end());
			ans += stoi(num[i]);
		}
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/9440