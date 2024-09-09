#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int N, K, M, J;
string S[100001];
unordered_map<string, int> um, v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> S[i];
		um.insert({ S[i], i });
	}
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		string str = S[now];
		for (int i = 0; i < K; i++)
		{
			str[i] = (str[i] == '1') ? '0' : '1';
			if (v.find(str) != v.end())
			{
				str[i] = (str[i] == '1') ? '0' : '1';
				continue;
			}
			auto iter = um.find(str);
			if (iter == um.end())
			{
				str[i] = (str[i] == '1') ? '0' : '1';
				continue;
			}
			v.insert({ str, now });
			q.push((*iter).second);
			str[i] = (str[i] == '1') ? '0' : '1';
		}
	}
	cin >> M;
	while (M--)
	{
		cin >> J;
		if (v.find(S[J]) == v.end())
		{
			cout << -1 << '\n';
			continue;
		}
		vector<int> ans;
		while (J != 1)
		{
			ans.push_back(J);
			J = v[S[J]];
		}
		ans.push_back(1);
		for (int i = ans.size() - 1; i >= 0; i--)
			cout << ans[i] << " ";
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/2481