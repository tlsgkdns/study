#include <iostream>
#include <queue>
using namespace std;

string str, ans = "";
int N, M, K, cnt = 0;
vector<int> t[4];
queue<pair<int, vector<int>>> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	cin >> str;
	for (int i = 0; i < N; i++)
	{
		int idx = 0;
		switch (str[i])
		{
		case 'A':
			idx = 0;
			break;
		case 'C':
			idx = 1;
			break;
		case 'G':
			idx = 2;
			break;
		default:
			idx = 3;
		}
		t[idx].push_back(i);
	}
	for (int i = 0; i < 4; i++)
	{
		if (t[i].size() < M) continue;
		q.push({ 1, t[i] });
	}
	while (!q.empty())
	{
		int L = q.front().first, idx = 0;
		vector<int> f = q.front().second;
		q.pop(); ++cnt;
		if (cnt == K)
			ans = string(str.begin() + f[0] - L + 1, str.begin() + f[0] + 1);
		vector<int> tmp[4];
		for (int i = 0; i < f.size(); i++)
		{
			if (f[i] >= N - 1) continue;
			switch (str[f[i] + 1])
			{
			case 'A':
				idx = 0;
				break;
			case 'C':
				idx = 1;
				break;
			case 'G':
				idx = 2;
				break;
			default:
				idx = 3;
			}
			tmp[idx].push_back(f[i] + 1);
		}
		for (int i = 0; i < 4; i++)
		{
			if (tmp[i].size() < M) continue;
			q.push({ L + 1, tmp[i] });
		}
	}
	cout << cnt << '\n' << ans << '\n';
}

// https://www.acmicpc.net/problem/2020