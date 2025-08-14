#include <iostream>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

int N, K, A;
queue<string> q;
unordered_map<string, int> v;
string input = "", f;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> A;
		input.push_back(A + '0');
		f.push_back(i + '0');
	}
	v[input] = 0;
	q.push(input);
	while (!q.empty())
	{
		string now = q.front();
		q.pop();
		int d = v[now];
		for (int i = 0; i <= now.size() - K; i++)
		{
			string nxt = now;
			reverse(nxt.begin() + i, nxt.begin() + i + K);
			if (v.find(nxt) != v.end()) continue;
			v[nxt] = d + 1;
			q.push(nxt);
		}
	}
	if (v.find(f) == v.end()) cout << -1 << '\n';
	else cout << v[f] << '\n';
}

// https://www.acmicpc.net/problem/1327